#include <iostream>

using namespace std;

class BaseDraw{
public:
    virtual void Draw(){
        cout << "BaseDraw:\n /\\ ";
    }
};

class Draw1: public BaseDraw{
public:
    void Draw() {
        cout << "Drawing 1:\n /\\ \n//\\\\" <<endl;
    }
};

class Draw2: public BaseDraw{
public:
    void Draw() {
        cout << "Drawing 2:\n /\\ \n/**\\" << endl;
    }
};

class Draw3: public BaseDraw{
public:
    void Draw() {
        cout << "Drawing 3:\n /\\ \n/++\\" <<endl;
    }
};

int main()
{
    BaseDraw *draws[3];
    draws[0] = new Draw1();
    draws[1] = new Draw2();
    draws[2] = new Draw3();

    for(int i = 0; i < 3; i++)
        draws[i]->Draw();

    return 0;
}
