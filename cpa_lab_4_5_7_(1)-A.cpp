#include <iostream>

using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);

    int prev = 0, prev1;
    int next, next1;


    while( ( next = sentence.find(" ", prev ) ) != string::npos ){
        prev1 = next + 1;
        next1 = sentence.find(" ", prev1 );

        if(sentence.substr( prev, next-prev ) == sentence.substr( prev1, next1-prev1))
            sentence.replace(prev,prev1-prev,"");
        prev = next + 1;
    }

    cout << sentence << "\n";
    return 0;
}
