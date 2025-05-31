#include "solution.h"
#include "rang.h"
#include "det.h"
#include "config.h"
#include "fraction.h"
#include <iostream>

extern int n, m, rangMaxim, **mat, *row, *col, **matAns;

int determinant, **auxMat = new int *[mxN + 1], coef[mxN];

fraction solve(int collumn, int rang)
{
    fraction auxAns;
    for (int i = 1; i <= rang; i++)
        auxMat[i][collumn] = coef[row[i]];

    auxAns = {det(rang, auxMat), determinant};

    for (int i = 1; i <= rang; i++)
        auxMat[i][collumn] = matAns[i][collumn];

    return auxAns;
}

bool isInCol(int j)
{
    for (int i = 1; i <= rangMaxim; i++)
        if (col[i] == j)
            return true;
    return false;
}

fraction *solution()
{
    fraction *ansMat = new fraction[mxN + 1];
    int ind;
    for (int i = 1; i <= mxN; i++)
        auxMat[i] = new int[mxN];
    for (int i = 1; i <= rangMaxim; i++)
        for (int j = 1; j <= rangMaxim; j++)
            auxMat[i][j] = matAns[i][j];

    if (m <= rangMaxim)
    {
        std::cout << "Imposibil\n";
        for (int i = 1; i <= m; i++)
            ansMat[i] = 0;
        return ansMat;
    }

    for (int i = 1; i <= n; i++)
    {
        ind = 1;
        for (int j = 1; j <= m; j++)
        {
            if (isInCol(j))
                ind++;
            else
            {
                ansMat[j] = 1;
                coef[i] -= mat[i][j];
            }
        }
    }

    determinant = det(rangMaxim, matAns);

    for (int i = 1; i <= rangMaxim; i++)
    {
        ansMat[col[i]] = solve(col[i], rangMaxim);
        std::cout << ansMat[col[i]];
    }

    // TO DO: make ansMat have only natural numbers(gcd the denominators, etc)

    return ansMat;
}