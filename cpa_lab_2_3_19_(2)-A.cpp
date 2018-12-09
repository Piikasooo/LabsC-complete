#include <iostream>

using namespace std;

int main()
{
    double pi4 = 0.;
    long n;

    cout << "Number of iterations? ";
    cin >> n;
    for (long i = 0, x = 1; i < n; i++, x += 2) {
        if(i % 2)
            pi4 -= 1./x;
        else
            pi4 += 1./x;
    }

    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;
    return 0;
}
