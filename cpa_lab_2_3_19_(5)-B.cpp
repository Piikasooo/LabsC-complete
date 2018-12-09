#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Input" << endl;
    cin >> n;
    if(n <= 0 || n >= 50)
    {
        cout << "Sorry, the side have to be a positive integer value greater than 0 and less than 50" << endl;
        return 0;
    }

    n -= 2; //Because we have a "+" on each side!!!
    cout << "Output" << endl;

    cout << '+';
    for(int i = 0; i < n; i++)
        cout << '-';
    cout << '+' << endl;
    for(int i = 0; i < n; i++)
    {
        cout << '|';
        for(int j = 0; j < n; j++)
            cout << ' ';
        cout << '|' << endl;
    }
    cout << '+';
    for(int i = 0; i < n; i++)
        cout << '-';
    cout << '+' << endl;
    return 0;
}
