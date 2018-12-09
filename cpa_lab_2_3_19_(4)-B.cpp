#include <iostream>

using namespace std;

int main()
{
    int n;
	double res = 1;
	cin >> n;
	for (int i = 0; i < n; ++i)
		res /= 2.;

    cout.precision(20);
	cout << res << endl;
    return 0;
}
