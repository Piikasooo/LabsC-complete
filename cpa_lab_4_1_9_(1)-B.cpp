#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
	double tempav = 0, overallfinal = 0;
	cin >> n;
	vector<vector<int>> allgrades = vector<vector<int>>();
	vector<double> avarages = vector<double>();
	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vector<int> tempgrades = vector<int>();

		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			tempav += temp;
			tempgrades.push_back(temp);
		}

		avarages.push_back(tempav / m);
		overallfinal += avarages[i];
		tempav = 0;
		allgrades.push_back(tempgrades);
	}

	overallfinal /= n;
	cout.precision(3);

	for (int i = 0; i < n; i++)
	{
		cout << "Course: " << i + 1 << " final: " << avarages[i] << " grades: ";

		for (int j = 0; j < allgrades[i].size(); j++)
		{
			cout << allgrades[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Overall final: " << overallfinal << endl;
    return 0;
}
