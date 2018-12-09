#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	try
	{
		if (b == 0) throw runtime_error("Your input is not valid, you can't divide by zero");
		c = a / b;
		cout << a << " / " << b << " = " << c << endl;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}
    return 0;
}
