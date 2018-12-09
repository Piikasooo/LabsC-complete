#include <iostream>

using namespace std;

int main()
{
    int year, day, month;
    cin >> year >> month >> day;
    month -= 2;
    if(month <= 0){
        month += 12;
        --year;
    }
    month = (13 * month - 1) / 5;
    month += day + year + year / 4 - year / 100 + year / 400;
    cout << endl << month % 7 << endl;
    return 0;
}
