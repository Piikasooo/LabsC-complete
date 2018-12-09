#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean = 0, HarmonicMean = 0, GeometricMean = 1, RootMeanSquare = 0;

	for (int i = 0; i < n; i++)
	{
		ArithmeticMean += vector[i];
		HarmonicMean += 1. / vector[i];
		GeometricMean *= vector[i];
		RootMeanSquare += vector[i] * vector[i];
	}

	ArithmeticMean /= n;
	HarmonicMean = n / HarmonicMean;
	GeometricMean = pow(GeometricMean, 1. / n);
	RootMeanSquare = pow(RootMeanSquare / n, 1. / 2);

	cout << "ArithmeticMean = " << ArithmeticMean << endl;
	cout << "HarmonicMean = " << HarmonicMean << endl;
	cout << "GeometricMean = " << GeometricMean << endl;
	cout << "RootMeanSquare = " << RootMeanSquare << endl;
    return 0;
}
