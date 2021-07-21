#include "Utils.h"

vector<string> Utils::split(const string& s, const string& delim)
{
	vector<string> result;
	int start = 0;
	int end = 0;
	while (end != string::npos) {
		end = s.find(delim, start);
		result.push_back(s.substr(start, end - start));
		start = end + delim.length();
	}
	return result;
}
