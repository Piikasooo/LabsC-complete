#include <iostream>

using namespace std;

struct Date
{
	int year;
	int day;
	int month;
};

bool isLeap(int year) {
    return year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
}

int monthLength(int year, int month){
    if (month == 2 && isLeap(year))
        return 29;

    int lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return lengths[month - 1];
}

int dayOfYear(Date date){
    int res = 0;
	for (int i = 1; i < date.month; i++)
		res += monthLength(date.year, i);
	return res + date.day;
}

int main()
{
    Date d;
    cout << "Enter year month day: ";
    cin >> d.year >> d.month >> d.day;
    cout << dayOfYear(d) << endl;

    return 0;
}
