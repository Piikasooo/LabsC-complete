#include <iostream>

using namespace std;

int main()
{
    int banknotes[]= { 50, 20, 10, 5, 1 };
    int clientMoney;
    cout << "Enter needed money: ";
    cin >> clientMoney;

    for(int i = 0; clientMoney > 0;)
    {
        if(clientMoney >= banknotes[i])
        {
            clientMoney -= banknotes[i];
            cout << banknotes[i] << ' ';
        }
        else ++i;
    }

    cout << endl;
    return 0;
}
