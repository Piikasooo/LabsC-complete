#include <iostream>

using namespace std;

class Engine
{
    public:
        Engine(string capacity = "1.0") {this->capacity = capacity;}
        void Print()
        {
            cout << "Engine: " << capacity << endl;
        }
    private:
        string capacity;
};

class Wheel
{
    public:
        Wheel(int diameter = 16) {this->diameter = diameter;}
        void Print()
        {
            cout << "Wheel: " << diameter <<"inches" << endl;
        }
    private:
        int diameter;
};

class Chassis
{
    public:
        Chassis(string type = "Normal") {this->type = type;}
        void Print()
        {
            cout << "Chassis: " << type << endl;
        }
    private:
        string type;
};

class Lights
{
    public:
        Lights() {}
        void SetType(string type) {this->type = type;}
        void Print()
        {
            cout << "Light: " << type << endl;
        }
    private:
        string type;
};

class Body
{
    public:
        Body(string color = "Black") {this->color = color;}
        void Print()
        {
            cout << "Body: " << color << endl;
        }
    private:
        string color;
};

class Car
{
    public:
        Car()
        {
            l0.SetType("Type 1");
            l1.SetType("Type 1");
            l2.SetType("Type 2");
            l3.SetType("Type 2");
            l4.SetType("Type 3");
            l5.SetType("Type 3");
            l6.SetType("Type 4");
            l7.SetType("Type 4");
            l8.SetType("Type 5");
            l9.SetType("Type 5");
        }
        void Print()
        {
            engine.Print();
            wh1.Print();
            wh2.Print();
            wh3.Print();
            wh4.Print();
            chassis.Print();
            l0.Print();
            l1.Print();
            l2.Print();
            l3.Print();
            l4.Print();
            l5.Print();
            l6.Print();
            l7.Print();
            l8.Print();
            l9.Print();
            body.Print();
        }
    private:
        Engine engine;
        Wheel wh1, wh2, wh3, wh4;
        Chassis chassis;
        Lights l0,l1, l2,l3,l4,l5,l6,l7,l8,l9;
        Body body;
};

int main()
{
    Car car;
    car.Print();
    return 0;
}
