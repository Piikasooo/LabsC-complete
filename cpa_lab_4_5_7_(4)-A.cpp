#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int index;
    cin >> s1 >> s2;

    if(s1.length() != s2.length())
    {
        cout << "not anagrams" << endl;
        return 0;
    }

    for(int i = 0; i < s1.length(); ++i)
    {
        index = s2.find(s1[i]);

        if(index == -1)
        {
            cout << "not anagrams" << endl;
            return 0;
        }
        s2.erase(index, 1);
    }

    cout << "anagrams" << endl;
    return 0;
}
