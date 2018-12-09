#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

const int DivideByZero = 111;
float internaldiv(float arg1, float arg2){
    if (arg2 == 0)
        throw DivideByZero;
    return arg1 / arg2;
}

float div(float arg1, float arg2){
    if(arg2 == 0.0)
        throw invalid_argument("Are you kidding me?\nYour input is not valid. You can't divide by zero.");

    return internaldiv(arg1, arg2);
}

float div2(float arg1, float arg2){
    return internaldiv(arg1, arg2);
}

int main(void){
    float a, b;

    cout << "Method that divide numbers choosing randomly!!!" << endl << endl;

    while(cin >> a) {
        cin >> b;
        try {
            cout << (rand() % 2 == 1 ? div(a,b) : div2(a, b)) << endl << endl;
        }
        catch (const exception& e){
            cout << e.what() << endl << "(Is better because we don't make unnecessary actions)" << endl << endl;
        }
        catch (int divideByZero){
            cout << "Can't divide by zero. Catched number is " << divideByZero << endl << endl;
        }
    }

    return 0;
}
