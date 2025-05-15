#include <iostream>
#include "rang.h"
#include "det.h"

using namespace std;

const int mxN = 1000;

extern int row[mxN + 1], col[mxN + 1];

int **mat = new int *[mxN + 1];

int main()
{
    int n, m, rangMaxim;
    for (int i = 1; i <= mxN; i++)
        mat[i] = new int[mxN];

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];

    rangMaxim = rangMatrix(n, m);
    cout << rangMaxim << "\n";

    for (int i = 1; i <= rangMaxim; i++)
    {
        cout << row[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i <= rangMaxim; i++)
    {
        cout << row[i] << " ";
    }
    cout << "\n";
    return 0;
}