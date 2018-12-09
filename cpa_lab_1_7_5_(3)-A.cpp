#include <iostream>

using namespace std;

bool isInRange(int number)
{
    return number > 0 && number < 256; //range [1, 255]
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(isInRange(a) && isInRange(b) && isInRange(c) && isInRange(d))
        cout << a << "." << b << "." << c << "." << d << endl;
    else
        cout << "Number must be in range [1, 255]" << endl;
    return 0;
}
