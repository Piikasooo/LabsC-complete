#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection {
    int elno;
    int *elements;
};

void AddToCollection(Collection &col, int element) {
    Collection temp = col;
    col.elements = new int[temp.elno + 1];
    for(int i = 0; i < temp.elno; ++i)
        col.elements[i] = temp.elements[i];

    col.elements[col.elno] = element;
    col.elno++;
    delete &temp;
}

void PrintCollection(Collection col) {
    cout << "[ ";
    for(int i = 0; i < col.elno; i++)
        cout << col.elements[i] << " ";
    cout << "]" << endl;
}

int main(void) {
    Collection collection = { 0, NULL };

    int elems;
    cout << "How many elements? ";
    cin >> elems;
    srand(time(NULL));

    for(int i = 0; i < elems; i++)
        AddToCollection(collection, rand() % 100 + 1);

    PrintCollection(collection);
    delete[] collection.elements;

    return 0;
}
