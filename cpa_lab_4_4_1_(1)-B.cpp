#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a="abcdefghijklmnopqrstuvwxyz", u, origin;
    int arra[a.length()] = {};
    getline(cin, u);
    bool v = true;
    int l = 0;
    origin = u;


    for(int i = 0; i < a.length(); ++i){
            if(u.find(a[i]) == string::npos)
            {
                u = origin;
                if(arra[i] == 0)
                    v = false;
            }
            else{
                arra[i]++;
                u = u.substr(u.find(a[i]) + 1);
                i--;
                continue;
            }
    }
    if(v)
        cout << "It is pangram" << endl;
    else
        cout << "It is not pangram" << endl;

    for(int i = 0; i < a.length(); ++i)
        cout << a[i] << " " << arra[i] << endl;

    return 0;
}
