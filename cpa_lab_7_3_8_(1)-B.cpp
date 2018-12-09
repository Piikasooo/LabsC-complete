#include <iostream>
#include <sstream>

using namespace std;

class IPnumbers
{
    public:
        IPnumbers(int octet1, int octet2, int octet3, int octet4)
        {
            if (octet1 > 256 || octet1 < 0 || octet2 > 256 || octet2 < 0 || octet3 > 256 || octet3 < 0 || octet4 > 256 || octet4 < 0)
                throw string("Exception - invalid IP number.");
            firstOctet = octet1;
            secondOctet = octet2;
            thirdOctet = octet3;
            fourthOctet = octet4;
        }
        void Print(int range)
        {
            if (range > 256 || range < 1)
                throw string("Exception - invalid range.");
            if ((range & (range - 1)) != 0)
                throw string("Exception - invalid range.");
            for(int i = 0; i < range; i++)
                cout << firstOctet <<"." << secondOctet << "." << thirdOctet << "." << fourthOctet++ << endl;
        }
    private:
        int firstOctet, secondOctet, thirdOctet, fourthOctet;
};

void func(string ip, int r)
{
    int oct1, oct2, oct3, oct4;
    while(ip.find(".") != -1)
        ip.replace(ip.find("."), 1, " ");

    try
    {
        istringstream (ip) >> oct1 >> oct2 >> oct3 >> oct4;
        IPnumbers ipn(oct1, oct2, oct3, oct4);
        ipn.Print(r);
        cout << endl;
    }
    catch(string &e){
        cout << e << endl;
    }
}

int main()
{
    string ip1, ip2, ip3, ip4;
    int r1, r2, r3, r4;

    cin >> ip1 >> r1;
    cin >> ip2 >> r2;
    cin >> ip3 >> r3;
    cin >> ip4 >> r4;

    cout << endl;
    func(ip1, r1);
    func(ip2, r2);
    func(ip3, r3);
    func(ip4, r4);
    return 0;
}
