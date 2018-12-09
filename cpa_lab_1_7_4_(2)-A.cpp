#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x1, x2;
    cout << "Enter first: ";
    cin >> x1;
    cout << "Enter second: ";
    cin >> x2;

    float fx1 = 1.0 / x1, fx2 = 1.0 / x2;
    cout << (abs(fx1-fx2) < 0.000001f ?
             "Results are equal (by 0.000001 epsilon)" : "Results are not equal (by 0.000001 epsilon)") << endl;

    return 0;
}
