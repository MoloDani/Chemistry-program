#include "det.h"

const int mxN = 1000;

int perm[mxN + 1];
long long ans = 0;
bool folosit[mxN + 1];

int sign(int n)
{
    int tot = 0;
    for (int i = 2; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            if (perm[i] < perm[j])
                tot++;

    if (tot % 2 == 0)
        return 1;
    return -1;
}

void lineVal(int n, int **mat)
{
    int aux = 1;
    for (int i = 1; i <= n; i++)
        aux *= mat[i][perm[i]];

    ans += sign(n) * aux;
}

void calcPerm(int pas, int n, int **mat)
{
    if (pas >= n)
    {
        lineVal(n, mat);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (folosit[i])
            continue;

        folosit[i] = true;
        perm[pas + 1] = i;

        calcPerm(pas + 1, n, mat);

        folosit[i] = false;
    }
}

long long det(int n, int **mat)
{
    calcPerm(0, n, mat);

    return ans;
}