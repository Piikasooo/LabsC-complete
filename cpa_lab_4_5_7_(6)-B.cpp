#include <iostream>
#include <regex>
#include <cctype>

using namespace std;

string Uper(string TheString ){
    TheString = TheString.substr(1, TheString.length() - 2);
    for(int i = 0; i < TheString.length(); i++){
        if(TheString[i] > 'z' || TheString[i] < 'a')
            continue;
		TheString[i] = TheString[i]  - 'a' + 'A';
    }
    return TheString;
}

string Under(string sentence, string r){
    regex star (r);
    smatch match;
    string s = " ";
    int p = 0;
    while(regex_search(sentence,match,star)){
        p = sentence.find(match[0]);
        s = match[0];

        sentence = sentence.erase(p,s.length());
        s = s.substr(1, s.length() - 2);
        for(int i = 1; i < s.length(); i += 2){
            s.insert(i, " ");
        }
        sentence.insert(p, s);
    }
    return sentence;
}

string Star(string sentence, string r,string rin){
    regex star (r);
    smatch match;
    string s = " ";
    int p = 0;
    while(regex_search(sentence, match, star)){
            p = sentence.find(match[0]);
        s = match[0];

        sentence = sentence.erase(p, s.length());
        s = Uper(s);
        sentence.insert(p, s);
    }
    sentence = Under(sentence, rin);

    return sentence;
}


int main()
{
    string sentence;
    getline(cin, sentence);

    sentence = Star(sentence, "\\*[^_]*\\*","_[^\\*]*_");

    while(sentence.find('*') != -1){
        sentence.erase(sentence.find('*'), 1);
    }
    while(sentence.find('_') != -1){
        sentence.erase(sentence.find('_'), 1);
    }

    cout << sentence << "\n";
    return 0;
}
