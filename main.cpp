#include <iostream>
#include "det.h"

using namespace std;

const int rows = 1000;

int main()
{
    int n;
    int **mat = new int *[rows + 1];
    for (int i = 1; i <= rows; i++)
        mat[i] = new int[rows];

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];

    cout << det(n, mat);
    return 0;
}