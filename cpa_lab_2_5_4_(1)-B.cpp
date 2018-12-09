#include <iostream>

using namespace std;

int main()
{
    int command;
	double a, b;

	while(true)
	{
	    cout << "MENU:" << endl << "0 - exit" << endl << "1 - addition" << endl << "2 - subtraction" << endl;
	    cout << "3 - multiplication" << endl << "4 - division" << endl << "Your choice?" << endl;
		cin >> command;
		if(command == 0)
            break;
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		switch (command)
		{
            case 1:
                cout << "Result a + b = " << a + b << endl << endl;
                break;
            case 2:
                cout << "Result a - b = " << a - b << endl << endl;
                break;
            case 3:
                cout << "Result a * b = " << a * b << endl << endl;
                break;
            case 4:
                cout << "Result a / b = " << a / b << endl << endl;
                break;
            default: break;
		}
	}

    return 0;
}
