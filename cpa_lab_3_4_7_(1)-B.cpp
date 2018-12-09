#include <iostream>

using namespace std;

int main()
{
    int vector[] = { 3, -50, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *temp = vector;
	int min = INT32_MAX;
	for (size_t i = 0; i < n; i++)
	{
		if (*temp < min) min = *temp;
		temp++;
	}

	cout << min << endl;
    return 0;
}
