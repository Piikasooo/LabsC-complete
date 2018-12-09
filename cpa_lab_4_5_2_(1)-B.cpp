#include <iostream>
#include <vector>

using namespace std;

bool String2Int(const std::string& str, int& result)
{
	std::string::const_iterator i = str.begin();

	if (i == str.end())
		return false;

	bool negative = false;

	if (*i == '-')
	{
		negative = true;
		++i;

		if (i == str.end())
			return false;
	}

	result = 0;

	for (; i != str.end(); ++i)
	{
		if (*i < '0' || *i > '9')
			return false;

		result *= 10;
		result += *i - '0';
	}

	if (negative)
	{
		result = -result;
	}

	return true;
}
string check(string s)
{
	vector<string> parts = vector<string>();
	string temp;
	int a;
	while (s.find_first_of('.') != string::npos)
	{
		temp = s.substr(0, s.find_first_of("."));

		if (temp.length() > 3) return "Too many characters in a part";
		if (!String2Int(temp, a)) return "Only digits and dots allowed";
		parts.push_back(temp);
		s = s.substr(s.find_first_of(".") + 1);
	}
	parts.push_back(s);
	if (parts.size() > 4) return "Too many parts";
	if (parts.size() < 4) return "Incorrect parts count";

		for (int i = 0; i < parts.size(); i++)
		{
			String2Int(parts[i].c_str(), a);
			if (a > 255 || a < 0) return "Too big a value of a part";
		}

	return "Correct IP";
}

int main()
{
	cout << "Type IP addresses and then \"end\", to see result" << endl;
	char temp;
	string line = "";
	vector<string> ips = vector<string>();

	do
	{
		cin >> line;
		ips.push_back(line);
	} while (line != "end");

	ips.resize(ips.size() - 1);
	for (int i = 0; i < ips.size(); i++)
		cout << check(ips[i]) << endl;

	return 0;
}
