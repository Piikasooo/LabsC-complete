#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(void) {
    int maxball;
    int ballsno;

    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;
    srand(time(NULL));

    if(ballsno > maxball){
        cout << "Can't to do it because: amount(" << ballsno << ") > max value(" << maxball << ")" << endl;
        return 0;
    }

    int *rands;
    rands = new int[ballsno];
    for (int i = 0; i < ballsno; i++) {
        do
            rands[i] = rand() % maxball + 1;
        while(count(rands, rands + ballsno, rands[i]) > 1);

        cout << rands[i] << " ";
    }

    return 0;
}
