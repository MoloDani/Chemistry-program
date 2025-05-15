#include "det.h"

const int mxN = 1000;

int perm[mxN];
long long ans = 0;

int sign(int n){
    int tot = 0;
    for(int i = 2; i <= n; i++)
        for(int j = i - 1; j >= 1; j--)
            if(perm[i] < perm[j])
                tot++;
    
    if(tot % 2 == 0)
        return 1;
    return -1;
}

void lineVal(int n){
    int aux = 1;    
    for(int i = 1; i <= n; i++){

    }
}

void calcPerm(int pas, int n){
    if(pas >= n){
        lineVal(n);
        return;
    }

    for(int i = perm[pas] + 1; i <= n; i++){
        perm[pas + 1] = i;

        calcPerm(pas + 1, n);
    }
}

long long det(int n, int **mat){
    calcPerm(0, n);

    return ans;
}