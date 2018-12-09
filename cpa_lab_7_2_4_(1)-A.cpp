#include <iostream>

using namespace std;

class MyExeption {
    public:
        string msg;
        MyExeption(string txt) : msg(txt) {}
};

float square_area(float a)
{
    if (a < 0)
        throw MyExeption("Your input is not valid. The area can't be negative.");
    return a * a;
}

float rectangle_area(float a, float b)
{
    if (a < 0 || b < 0)
        throw MyExeption("Your input is not valid. The area can't be negative.");
    return a * b;
}

int main()
{
    float a, b, r;
    cin >> a;
    cin >> b;
    try
    {
        float rsquare = square_area(a);
        float rrectangle = rectangle_area(a,b);
        cout << rsquare << endl << rrectangle << endl;
    }
    catch(MyExeption ex)
    {
        cout << ex.msg << endl;
    }
    return 0;
}
