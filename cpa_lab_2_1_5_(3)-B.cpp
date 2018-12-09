#include <iostream>

using namespace std;

int main()
{
    int sys;
    float m, ft, in;

    cout << "Enter system (0 means \"metric\" and 1 means \"imperial\"): ";
    cin >> sys;
    if (sys) {
        cout << "Enter feet: ";
        cin >> ft;
        cout << "and inches: ";
        cin >> in;
        in += ft * 12.0;
        cout << in / 39.37008 << "m";
    }
    else {
        cout << "Enter meters: ";
        cin >> m;
        in = m * 39.37008;
        ft = (int)in / 12;
        in -= ft * 12;
        cout << ft << "'" << in << "\"";
    }
    return 0;
}
