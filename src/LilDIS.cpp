#include "LilDIS.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <istream>
#include <array>
#include "Utils.h"

Utils utils;

string LilDIS::read(string key)
{
	for (size_t i = 0; i < keysDB.size(); i++)
	{
		if (keysDB[i] == key)
		{
			return valuesDB[i];
		}
	}
	return "NULL";
};

bool LilDIS::write(string key, string value)
{
	int key_index = this->get_key_index(key);

	if (this->get_key_index(key) == -1) /* When key doesn't exists in keysDB vector it returns -1 */
	{
		this->push_data_to_ram(key, value);

		return true;
	}
	valuesDB[key_index] = value;
	return true;
}

bool LilDIS::delet(string key)
{
	int key_index = this->get_key_index(key);

	if (this->get_key_index(key) != -1) /* When key doesn't exists in keysDB vector it returns -1 */
	{
		keysDB.erase(keysDB.begin() + key_index);
		valuesDB.erase(valuesDB.begin() + key_index);
		return true;
	}
	return false;
}

int LilDIS::get_key_index(string key)
{
	for (size_t i = 0; i < keysDB.size(); i++)
	{
		if (keysDB[i] == key)
		{
			return i;
		}
	}
	return -1;
}

bool LilDIS::push_data_to_ram(string key, string value)
{
	keysDB.push_back(key);
	valuesDB.push_back(value);
	return true;
}

bool LilDIS::write_data_to_disk()
{
	ofstream LilDBWrite("db.lil");
	LilDBWrite << "";
	LilDBWrite.close();

	ofstream LilDBAppend("db.lil", ios_base::app | ios_base::out);

	for (size_t i = 0; i < keysDB.size(); i++)
	{
		if (i != 0)
		{
			LilDBAppend << "\n";
		}
		LilDBAppend << keysDB[i] + " = " + valuesDB[i];
	}

	return true;
}

bool LilDIS::read_data_from_disk()
{
	ifstream LilDB("db.lil");
	if (LilDB.is_open()) {
		string line;
		while (getline(LilDB, line)) {
			vector<string> splitted_data = utils.split(line.c_str(), " = ");

			this->push_data_to_ram(splitted_data[0], splitted_data[1]);
		}
		LilDB.close();
	}
	return true;
}

bool LilDIS::check_db_exists()
{
	return filesystem::exists("db.lil");
}

bool LilDIS::create_db()
{
	try
	{
		ofstream LilDBFile("db.lil");
		LilDBFile << "test = hello world";
		LilDBFile.close();

		return true;
	}
	catch (const std::exception&)
	{
		cout << "[ERROR]There was a problem creating the database!";
		return false;
	}
}
