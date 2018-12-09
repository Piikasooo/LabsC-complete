#include <iostream>
#include <vector>

using namespace std;

void takeFirstElementSeparatedByComma(string &values, int commaIndex, vector<string> &key, vector<string> &value)
{
    string substring;
    int equalIndex;

    substring = values.substr(0,commaIndex);
    equalIndex = substring.find("=");
    key.push_back("[" + substring.substr(0, equalIndex) + "]");
    value.push_back(substring.substr(equalIndex + 1));
    values.erase(0, commaIndex + 1);
}

int main()
{
    string values;
    vector<string> key, value;
    getline(cin, values);
    string mytemplate;
    getline(cin, mytemplate);
    int commaIndex = values.find(",");
    int regexIndex;

    while(commaIndex != -1) //Take all keys and values before each comma
    {
        takeFirstElementSeparatedByComma(values, commaIndex, key, value);
        commaIndex = values.find(",");
    }
    takeFirstElementSeparatedByComma(values, values.length(), key, value); //take last key and value, after all commas

    for(int i = 0; i < key.size(); ++i)
    {
        regexIndex = mytemplate.find(key[i]);
        while(regexIndex != -1)
        {
            mytemplate.replace(regexIndex, key[i].length(), value[i]);
            regexIndex = mytemplate.find(key[i]);
        }
    }

    cout << mytemplate << "\n";
    return 0;
}
