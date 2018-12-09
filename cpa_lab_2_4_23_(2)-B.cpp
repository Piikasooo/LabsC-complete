#include <iostream>

using namespace std;

int main()
{
    unsigned short int val, q = 0;
    unsigned short int n = 32768;

    cout << "value = ";
    cin >> val;
    for(int i = 0; i < 16; ++i)
    {
        if(n & val)
            q |= 32768 / n;
        n >>= 1;
    }
    if(q == val)
        cout << val << " is a bitwise palindrome" << endl;
    else
        cout << val << " is not a bitwise palindrome" << endl;

    return 0;
}
