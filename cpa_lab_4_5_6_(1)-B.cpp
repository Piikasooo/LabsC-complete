#include <iostream>

using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);
    int index = sentence.find("  ");

    while(index != -1)
    {
        sentence.replace(index, 2, " ");
        index = sentence.find("  ");
    }

    cout << sentence << "\n";
    return 0;
}
