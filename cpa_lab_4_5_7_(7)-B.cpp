#include <iostream>

using namespace std;

int main()
{
    string temp;

	cin >> temp;
	std::string password = temp;
	bool flag = true;

	temp = "        ";
	if (password.size() < 8)
	{
		cout << "The password must be 8 characters long" << endl;
		flag = false;
	}

	temp = "";
	for (int i = 0; i < password.size(); i++)
		temp += tolower(password[i]);

	if (temp == password)
	{
		cout << "The password must have at least one upper-case letter" << endl;
		flag = false;
	}

	temp = "";
	for (int i = 0; i < password.size(); i++)
		temp += toupper(password[i]);

	if (temp == password)
	{
		cout << "The password must have at least one lower-case letter" << endl;
		flag = false;
	}

	temp = "";
	for (int i = 0; i < password.size(); i++)
		if (!isdigit(password[i])) temp += password[i];

	if (temp == password)
	{
		cout << "The password must have at least one digit" << endl;
		flag = false;
	}

	temp = "";
	for (int i = 0; i < password.size(); i++)
		if (isdigit(password[i]) || isalpha(password[i])) temp += password[i];

	if (temp == password)
	{
		cout << "The password must have at least one special character." << endl;
		flag = false;
	}

	if (flag)
        cout << "The password is valid" << endl;
    return 0;
}
