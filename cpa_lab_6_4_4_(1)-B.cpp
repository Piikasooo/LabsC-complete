#include <iostream>

using namespace std;

class StringValidator{
    public:
        virtual ~StringValidator() {};
        virtual bool isValid(string input) = 0;
};

class ExactValidator : public StringValidator {
    private:
        string exactString;
    public:
        ExactValidator(string str);
        virtual bool isValid(string input);
};

ExactValidator::ExactValidator(string str) : exactString(str) {}

bool ExactValidator::isValid(string input)
{
    return input == this->exactString;
}

class DummyValidator : public StringValidator {
    public:
        virtual bool isValid(string input);
};

bool DummyValidator::isValid(string input){
    return true;
}

void printValid(StringValidator &validator, string input){
    cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main(){
    DummyValidator dummy;
    printValid(dummy, "hello");
    cout << endl;
    ExactValidator exact("secret");
    printValid(exact, "hello");
    printValid(exact, "secret");
    return 0;
}
