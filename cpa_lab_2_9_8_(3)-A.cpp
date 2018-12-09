#include <iostream>

using namespace std;

int main()
{
    int vector[] = {5, 1, 7, 3, 8, 3, 7, 1, 5};
    bool ispalindrome = true;
    int n = sizeof(vector) / sizeof(vector[0]);

    for(int i = 0; i < n / 2; ++i)
    {
        if(vector[i] != vector[n - 1 - i])
        {
            ispalindrome=false;
            break;
        }
    }

    if(ispalindrome)
        cout << "It's a palindrome";
    else
        cout << "It isn't a palindrome";
    cout << endl;
    return 0;
}
