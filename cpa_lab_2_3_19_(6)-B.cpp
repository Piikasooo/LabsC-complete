#include <iostream>

using namespace std;

int main()
{
    int h;
    string pyramids;
    cout << "Enter pyramid`s height (h, 2 < h < 9): ";
    cin >> h;
    if (h <= 2 || h >= 9)
        return 1;
    for(int i = 0; i < h - 1; ++i)
    {
        for (int j = 0; j < 3; ++j) //3 pyramids
            for(int k = 0; k < 2 * h + 1; ++k)
                if(h - i == k || h + i == k)
                    pyramids += "*";
                else pyramids += " ";
        pyramids += "\n";
    }
    for(int i = 0; i < 3; ++i) //3 pyramids
    {
        pyramids += " ";
        for(int j = 0; j < 2 * h - 1; ++j)
            pyramids += "*";
        pyramids += " ";
    }
    pyramids += "\n";

    cout << pyramids;
    return 0;
}
