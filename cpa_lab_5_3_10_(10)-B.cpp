#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Fraction {
    public:
        Fraction(int numerator, int denominator);
        string toString();
        double toDouble();
        Fraction plus(Fraction that);
        Fraction minus(Fraction that);
        Fraction times(Fraction that);
        Fraction by(Fraction that);
        bool isGreaterThan(Fraction that);
        bool isLessThan(Fraction that);
        bool isEqual(Fraction that);
    private:
        int numerator;
        int denominator;
        void reduce();
};

void Fraction::reduce() {
	int a;
	if (this->numerator < 0)
		a = -this->numerator;
	else
		a = this->numerator;
	int b = this->denominator;
	while (a != 0 && b != 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	this->numerator /= (a + b);
	this->denominator /= (a + b);
}
Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::plus(Fraction that)
{
	int den = this->denominator * that.denominator;
	int num = that.denominator * this->numerator + that.numerator * this->denominator;

	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::minus(Fraction that)
{
	int den = this->denominator * that.denominator;
	int num = that.denominator * this->numerator - that.numerator * this->denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction::Fraction(int numerator, int denominator) {
	if (denominator == 0) {
		this->denominator = 1;
		this->numerator = numerator;
	}
	else if (denominator < 0) {
		this->denominator = -denominator;
		this->numerator = -numerator;
	}
	else {
		this->denominator = denominator;
		this->numerator = numerator;
	}
}

string to_string(int value){
    stringstream ss;
    ss << value;
    return ss.str();
}

string Fraction::toString() {
	if (numerator * denominator < 0)
	{
		if (numerator % denominator == 0)
			return to_string(numerator / denominator);
		if (numerator / denominator == 0)
			return to_string(numerator) + (string)"/" + to_string(denominator);
		return to_string(numerator / denominator) + (string)" " +
            to_string(-(numerator % denominator)) + (string) "/" + to_string(denominator);
	}
	if (numerator % denominator == 0)
		return to_string(numerator / denominator);
	if (numerator / denominator == 0)
		return to_string(numerator) + (string)"/" + to_string(denominator);
	return to_string(numerator / denominator) + (string)" " +
        to_string(numerator % denominator) + (string) "/" + to_string(denominator);


}
double Fraction::toDouble() {
	return float(numerator) / denominator;
}
bool Fraction::isGreaterThan(Fraction that)
{
	return this->toDouble() > that.toDouble();
}
bool Fraction::isLessThan(Fraction that)
{
	return this->toDouble() < that.toDouble();
}
bool Fraction::isEqual(Fraction that)
{
	return this->toDouble() == that.toDouble();
}
int main(void) {
	int num, den;
	std::string input = "", i2;
	getline(cin, input);

	num = atoi((input.substr(0, input.find("/"))).c_str());
	den = atoi((input.substr(input.find("/") + 1)).c_str());
	Fraction fraction1(num, den);
	getline(cin, i2);

	num = atoi((i2.substr(0, i2.find("/"))).c_str());
	den = atoi((i2.substr(i2.find("/") + 1)).c_str());
	Fraction fraction2(num, den);

	if (fraction1.isGreaterThan(fraction2))
		cout << fraction1.toString() << " > " << fraction2.toString() << endl;
	if (fraction1.isLessThan(fraction2))
		cout << fraction1.toString() << " < " << fraction2.toString() << endl;
	if (fraction1.isEqual(fraction2))
		cout << fraction1.toString() << " = " << fraction2.toString() << endl;

	return 0;
}
