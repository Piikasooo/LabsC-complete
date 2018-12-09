#include <iostream>

using namespace std;

int main()
{
    int vector1[10] = {4, 7, 2, 8, 1, 3, 0, 9, 1, 5};
    int vector2[10];
    int vector1Length = sizeof(vector1) / sizeof(*vector1);
    int vector2Length = sizeof(vector2) / sizeof(*vector2);

    vector2[0] = vector1[vector1Length - 1];
    for(int i = 1; i < vector1Length && i < vector2Length; ++i) //if someone will want to change only one vector size
        vector2[i] = vector1[i - 1];

    for(int i = 0; i < vector2Length; i++)
        cout << vector2[i] << ' ';
    cout << endl;
    return 0;
}
