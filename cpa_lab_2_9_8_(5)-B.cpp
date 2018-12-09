#include <iostream>

using namespace std;

int main()
{
    double matrix[][5] = {
        { 1, 2, 3, 4, 1 },
        { 2, 2, 3, 1, 1 },
        { 3, 3, 3, 2, 1 },
        { 4, 1, 2, 4, 1 },
        { 1, 1, 1, 1, 2 }};
    int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    bool issymmetric = true;
    int matrixSize = sizeof(matrix) / sizeof(*matrix);

    issymmetric = side == matrixSize;

    for(int i = 0; issymmetric && i < side; ++i)
        for(int j = i + 1; issymmetric && j < side; ++j)
            issymmetric = matrix[i][j] == matrix[j][i];

    if(issymmetric)
        cout << "The matrix is symmetric" << endl;
    else
        cout << "The matrix is not symmetric" << endl;
    return 0;
}
