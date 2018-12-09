#include <iostream>

using namespace std;

int main()
{
    int a = 8, b = 0, c = 0;
    cout << "Divide 8 on: (enter number)" << endl;
    cin >> b;
    try {
        if (b == 0)
            throw string("Your input is not valid, you can't divide by zero.");
        c = a / b;
    }
    catch (string e) {
        cout << e << endl;
    }

    cout << "Result is: " << c << endl;
    return 0;
}
