#include <iostream>
#include <vector>

using namespace std;

bool iequals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

vector<string> split(string s, char c)
{
	vector<string> res = vector<string>();
	string temp;

	do
	{
		temp = s.substr(0, s.find_first_of(c));
		res.push_back(temp);
		s = s.substr(s.find_first_of(c) + 1);
	}while (s.find_first_of(c) != string::npos);

	res.push_back(s);
	return res;
}

int main()
{
	string stop_words, sentence;
	getline(cin, stop_words);

	vector<string> words = split(stop_words, ',');

	getline(cin, sentence);
	bool print = false;
	vector<string> sent = split(sentence, ' ');

	for (int i = 0; i < sent.size(); i++)
	{
		print = true;
		for (int j = 0; j < words.size(); j++)
			if (iequals(words[j], sent[i]))
				print = false;
		if (print)
            cout << sent[i] << " ";
	}

	cout << endl;

    return 0;
}
