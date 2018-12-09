#include <iostream>
#include <vector>

using namespace std;

class Caretaker
{
    private:
        int value, minvalue, maxvalue;
    public:
        Caretaker(int val, int minval, int maxval)
        {
            value = val;
            minvalue = minval;
            maxvalue = maxval;
        }
        void Add(int a)
        {
            int temp = value + a;
            if (temp > maxvalue || temp < minvalue) { throw "Value could exceed limit"; }
            else value = temp;
        }
        void Substruct(int a)
        {
            Add(-a);
        }
        int GetValue()
        {
            return value;
        }
};

int main()
{
	int a, mina, maxa;
	vector<Caretaker> caretakers;
	for(int i = 0; i < 2; ++i){
        cout << "enter value number " << i << endl;
        cin >> a;
        cout << "enter min value number " << i << endl;
        cin >> mina;
        cout << "enter max value number " << i << endl;
        cin >> maxa;

        caretakers.push_back(Caretaker(a, mina, maxa));
	}

	cout << "enter value to add" << endl;
	cin >> a;

    for(int i = 0; i < 2; ++i)
        try
        {
            caretakers[i].Add(a);
            cout << "Value number " << i << " + " << a << " = " << caretakers[i].GetValue() << endl;
        }
        catch (...)
        {
            cout << "Value number " << i << " could exceed limit" << endl;
        }

	cout << "enter value to substruct" << endl;
	cin >> a;

	for(int i = 0; i < 2; ++i)
        try
        {
            caretakers[i].Substruct(a);
            cout << "Value number " << i << " - " << a << " = " << caretakers[i].GetValue() << endl;
        }
        catch (...)
        {
            cout << "Value number " << i << " could exceed limit" << endl;
        }

    return 0;
}
