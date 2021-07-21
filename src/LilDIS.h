#pragma once
#include <string>
#include <vector>

using namespace std;

class LilDIS
{
public:
	string read(string key);
	bool write(string key, string value);
	bool delet(string key);
	int get_key_index(string key);
	bool push_data_to_ram(string key, string value);
	bool write_data_to_disk();
	bool read_data_from_disk();
	bool check_db_exists();
	bool create_db();
private:
	vector<string> keysDB;
	vector<string> valuesDB;
};