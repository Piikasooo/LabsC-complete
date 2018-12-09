#include <iostream>

using namespace std;

int main()
{
    float grossprice, taxrate, netprice, taxvalue;
    do
    {
        cout << "Enter a gross price (greater than 0): ";
        cin >> grossprice;
    } while(grossprice <= 0);
    do
    {
        cout << "Enter a tax rate (greater than 0 and less than 100): ";
        cin >> taxrate;
    } while (taxrate <= 0 || taxrate >= 100);

    netprice = grossprice / (1 + taxrate / 100);
    taxvalue = grossprice - netprice;

    cout << "Net price: " << netprice << endl;
    cout << "Tax value: " << taxvalue << endl;
    return 0;
}
