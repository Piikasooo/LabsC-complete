#include <iostream>

using namespace std;

int main()
{
    float v1, v2, v3, v4, v5;
    cout << "Input values:" << endl;
    cin >> v1 >> v2 >> v3 >> v4 >> v5;
    cout << "Output values:" << endl << fixed;
    cout.precision(1);
    cout << v1 << endl;
    cout.precision(2);
    cout << v2 << endl;
    cout.precision(6);
    cout << v3 << endl;
    cout.precision(2);
    cout << v4 << endl;
    cout.precision(0);
    cout << v5;
    return 0;
}
