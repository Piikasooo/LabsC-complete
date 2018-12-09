#include <iostream>

using namespace std;

int main()
{
    int year;
	cin >> year;
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int d = (a * 19 + 24) % 30;
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;

	cout << (d + e < 10 ? "March " : "April ") << (d + e < 10 ? d + e + 22 : d + e - 9 ) << endl;
    return 0;
}
