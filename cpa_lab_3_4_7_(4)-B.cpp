#include <iostream>

using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
}

int monthLength(int year, int month){
    if (month == 2 && isLeap(year))
        return 29;

    int lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return lengths[month - 1];
}

int main(void) {
    for(int yr = 2000; yr < 2002; yr++) {
        for(int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr,mo) << " ";
        cout << endl;
    }

    return 0;
}
