#include <iostream>

using namespace std;

int main()
{
    int c0, i = 0;
    cout << "Input:" << endl;
    cin >> c0;
    cout << "Output:" << endl;
    while (c0 != 1)
    {
        ++i;
        if(c0 % 2 == 0)
            c0 /= 2;
        else c0 = 3 * c0 + 1;
        cout << c0 << endl;
    }
    cout << "steps = " << i;
    return 0;
}
