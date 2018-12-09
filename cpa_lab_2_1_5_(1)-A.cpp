#include <iostream>

using namespace std;

int main()
{
    int year;

    cout << "Enter a year: ";
	cin >> year;

	cout << (year % 4 != 0 || year % 100 == 0 && year % 400 != 0 ? "Common" : "Leap") << " year" << endl;
    return 0;
}
