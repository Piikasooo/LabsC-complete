#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int myfield[3][3], enemyfield[3][3];

int main()
{
    cout << "BattleShip. Draw your battlefield and setup ships. Then enter coordinates of your shoot in format x y (0 <= x, y < 3)" << endl;
	srand(time(0));
	myfield[rand() % 3][rand() % 3] = 1;
	string line = "";
	int xe, ye, x, y;
	do {
		do {
			x = rand() % 3;
			y = rand() % 3;
		} while (enemyfield[x][y] == -1);
		enemyfield[x][y] = -1;

		do
		{
			cin >> line;
			xe = atoi(line.c_str());
			cin >> line;
			ye = atoi(line.c_str());
		} while (myfield[xe][ye] == -1);

		if (myfield[xe][ye] == 1) break;
		myfield[xe][ye] = -1;

		cout << "comp: ";
		cout << x << " " << y << endl;
	} while(true);

	cout << "you win" << endl;
    return 0;
}
