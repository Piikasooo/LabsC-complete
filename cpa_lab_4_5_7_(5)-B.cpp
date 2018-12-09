#include <iostream>
#include <regex>

using namespace std;

void regReplace(string &pattern, string symb, string regsymb){
    int index = pattern.find(symb, 0);
    while(index != -1){
        pattern.replace(index, 1, regsymb);
        index = pattern.find(symb, index);
    }
}

int main()
{
    int nextPosition;
    string pattern;
    getline(cin, pattern);
    string s;
    getline(cin, s);

    regReplace(pattern, "D", "[0-9]");
    regReplace(pattern, "A", "\\w");
    regReplace(pattern, "?", ".");

    regex rgx(pattern);
    smatch match;

    while (regex_search(s, match, rgx)) {
        cout << match[0] << endl;
        nextPosition = match.position() + 1;

        if(nextPosition == s.length())
            break;

        s = s.substr(nextPosition);
    }

    return 0;
}
