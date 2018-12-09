#include <iostream>
#include <vector>

using namespace std;

class IPAddress
{
    protected:
            string ip;
    public:
        IPAddress(const IPAddress &ip)
        {
            this->ip = ip.ip;
        };
        IPAddress(string ip)
        {
            this->ip = ip;
        };
        void virtual Print()
        {
            cout << this->ip << endl;
        }
};

class CheckedIPAddress : IPAddress
{
    public:
        CheckedIPAddress(string ip) : IPAddress(ip)
        {
            correct = check(ip);
        }
        CheckedIPAddress(const CheckedIPAddress &ip) : IPAddress(ip)
        {
            this->correct = ip.correct;
        }
        void Print()
        {
            cout << this->ip << (correct ? " - Correct" : " - Not Correct") << endl;
        }
    private:
        bool correct;

        bool String2Int(const string& str, int& result) {
            string::const_iterator i = str.begin();

            if (i == str.end())
                return false;

            bool negative = false;

            if (*i == '-')
            {
                negative = true;
                ++i;

                if (i == str.end())
                    return false;
            }

            result = 0;

            for (; i != str.end(); ++i)
            {
                if (*i < '0' || *i > '9')
                    return false;

                result *= 10;
                result += *i - '0';
            }

            if (negative)
            {
                result = -result;
            }

            return true;
        }
        bool check(string s) {
            vector<string> parts = vector<string>();
            string temp;
            int a;
            while (s.find_first_of('.') != string::npos)
            {
                temp = s.substr(0, s.find_first_of("."));

                if (temp.length() > 3) return false;
                if (!String2Int(temp, a)) return false;
                parts.push_back(temp);
                s = s.substr(s.find_first_of(".") + 1);
            }
            parts.push_back(s);
            if (parts.size() > 4) return false;
            if (parts.size() < 4) return false;

            for (int i = 0; i < parts.size(); i++)
            {
                String2Int(parts[i].c_str(), a);
                if (a > 255 || a < 0) return false;
            }

            return true;
        }
};

int main()
{
	string sIP, sCIP, sCIP2;

	cin >> sIP;
	cin >> sCIP;
	cin >> sCIP2;

	IPAddress ip = IPAddress(sIP);
	CheckedIPAddress cip = CheckedIPAddress(sCIP);
	CheckedIPAddress cip2 = CheckedIPAddress(sCIP2);

    cout << endl;
	ip.Print();
	cip.Print();
	cip2.Print();


	return 0;
}
