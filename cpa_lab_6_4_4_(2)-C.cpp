#include <iostream>
#include <regex>

using namespace std;

class StringValidator
{
    public:
        virtual ~StringValidator() {};
        virtual bool isValid(string input) = 0;
};

class MinLengthValidator: public StringValidator
{
    public:
        MinLengthValidator(int length)
        {
            this->length = length;
        }
        bool isValid(string input)
        {
            return input.length() > length;
        }
    private:
        int length;
};

class MaxLengthValidator: public StringValidator
{
    public:
        MaxLengthValidator(int length)
        {
            this->length = length;
        }
        bool isValid(string input)
        {
            return input.length() < length;
        }
    private:
        int length;
};

class PatternValidator: public StringValidator
{
    public:
        PatternValidator(string ptr)
        {
            regReplace(ptr, "D", "[0-9]");
            regReplace(ptr, "A", "\\w");
            regReplace(ptr, "?", ".");
            pattern = ptr;
        }
        void regReplace(string &pattern, string symb, string regsymb)
        {
            int prev = 0;
            int index = pattern.find(symb,prev);
            while(index != -1)
            {
                pattern.replace(index,1,regsymb);
                prev=index;
                index = pattern.find(symb,prev);
            }
        }
        bool isValid(string input)
        {
            regex rgx(pattern);
            return regex_search(input, rgx);
        }
    private:
        string pattern;
};

void printValid(StringValidator &validator, string input)
{
    cout << "The string '" << input << "' is "
    << (validator.isValid(input) ? "valid" : "invalid") <<endl;
}

int main()
{
    cout << "MinLength Validator" << endl;
    MinLengthValidator min(6);
    printValid(min, "hello");
    printValid(min, "welcome");
    cout << endl;

    cout << "MaxLength Validator" << endl;
    MaxLengthValidator max(6);
    printValid(max, "hello");
    printValid(max, "welcome");
    cout << endl;

    cout << "Pattern Validator" << endl;
    PatternValidator digit("D");
    printValid(digit, "there are 2 types of sentences in the world");
    printValid(digit, "valid and invalid ones");
    cout << endl;

    return 0;
}
