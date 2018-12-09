#include <iostream>

using namespace std;

struct TIME{
    int hour;
    int minute;
};

int main()
{
    int event;
    TIME time;

    do
    {
        cout << "Enter hours (value must be in range [0;23]): ";
        cin >> time.hour;
    } while(time.hour < 0 || time.hour > 23);
    do
    {
        cout << "Enter minutes (value must be in range [0;59]): ";
        cin >> time.minute;
    } while(time.minute < 0 || time.minute > 59);

    cout << "Enter duration event in minutes: ";
    cin >> event;
    time.hour =((event + time.minute) / 60 + time.hour) % 24;
    time.minute = (event + time.minute) % 60;

    cout << time.hour << ":" << time.minute << endl;
    return 0;
}
