#include "det.h"
#include "config.h"

int perm[mxN + 1];
long long ans = 0;
bool folosit[mxN + 1];

int **matrix = nullptr;
static int n;

int sign()
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

void lineVal()
{
    int aux = 1;
    for (int i = 1; i <= n; i++)
        aux *= matrix[i][perm[i]];

    ans += sign() * aux;
}

void calcPerm(int pas)
{
    if (pas >= n)
    {
        lineVal();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (folosit[i])
            continue;

        folosit[i] = true;
        perm[pas + 1] = i;

        calcPerm(pas + 1);

        folosit[i] = false;
    }
}

void init()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        perm[i] = 0;
        folosit[i] = false;
    }
}

long long det(int nAux, int **m)
{
    init();
    n = nAux;
    matrix = m;
    calcPerm(0);

    return ans;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return (a > 0 ? a : -a);
}