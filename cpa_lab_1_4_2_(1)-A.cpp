#include <iostream>

using namespace std;

int main()
{
    float v = 2;
    float result = (v + 1) * 2;
    cout << "result:  " << result <<  "  expected result :  6" << endl;
    result = (v + 1) * (v + 2) * 2;
    cout << "result: " << result <<  "  expected result : 24" << endl;
    result = (v - 1) * 2 + 2 * 2;
    cout << "result:  " << result <<  "  expected result :  6" << endl;
    result = (v + v) * (v + v) * 2;
    cout << "result: " << result <<  "  expected result : 32" << endl;
    result = (int)v % 2 * (v + 2) * 2;
    cout << "result:  " << result <<  "  expected result :  0" << endl;
    return 0;
}
