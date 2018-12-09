#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Fraction{
public:
    Fraction(int numerator, int denominator) {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    string toString(){
        ostringstream s;
        if(numerator / denominator < 0)
            s << "-";
        if(numerator / denominator != 0)
            s << abs(numerator / denominator) << " ";
        if(numerator % denominator != 0)
            s << (numerator % denominator) << "/" << abs(denominator);
        return  s.str();
    };
    double toDouble(){
        return (double)numerator / denominator;
    };
private:
    int numerator;
    int denominator;
};

int main(void) {
    int num, den;
    string input = "";
    getline(cin,input);

    input.replace(input.find("/"),1," ");
    istringstream ss(input);
    ss >> num >> den;
    if (den == 0) {
        cout << "The denominator should not be 0";
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}
