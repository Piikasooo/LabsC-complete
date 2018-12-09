аш#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long first = 1, second = 1, third = 1;

    for(int i = 0; i < n - 2; ++i)
    {
        third=first+second;
        first=second;
        second=third;
    }

    cout << third << endl;
    return 0;
}
