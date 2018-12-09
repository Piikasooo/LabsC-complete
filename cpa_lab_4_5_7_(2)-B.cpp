#include <iostream>

using namespace std;

int main()
{
    string from;
    getline(cin, from);
    string to;
    getline(cin, to);
    string sentence;
    getline(cin, sentence);

    while(sentence.find(from) != string::npos){
        sentence = sentence.replace(sentence.find(from), from.length(), to);
    }

    cout << sentence << "\n";
    return 0;
}
