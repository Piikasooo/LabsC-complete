#include <iostream>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

bool isLeap(int year){
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

int daysBetween(Date d1, Date d2){
    if(d1.year > d2.year)
        return -1;

    int daysCount = dayOfYear(d2) - dayOfYear(d1); //At first count days in last year
    if(d1.year == d2.year && daysCount < 0)
        return -1;

    for(int i = d1.year; i < d2.year; ++i) //Then count previous years
        daysCount += isLeap(i) ? 366 : 365;
    return daysCount;
}

int main()
{
    Date since,till;
    cout << "Enter first date (y m d): ";
    cin >> since.year >> since.month >> since.day;
    cout << "Enter second date (y m d): ";
    cin >> till.year >> till.month >> till.day;
    cout << daysBetween(since,till) << endl;
    return 0;
}
