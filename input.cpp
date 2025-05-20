#include <iostream>
#include "input.h"

extern **mat;

const int mxC = 100001;

char elements[101][mxC];
bool firstPart[mxC];
int noElem = 0;
char ecuation[mxC];

bool iCanContinue(int i)
{
    return (ecuation[i] != '+' && ecuation[i] != '=');
}

void input()
{
    int ind = 1, l = 1;
    std::cout << "Introdu ecuația pe care vrei sa o egalez: ";
    std::cin >> ecuation;

    while (ecuation[ind] != '\0')
    {
        int aux = 0;
        while (iCanContinue(ind) && ecuation[ind] != '\0')
            l++, ind++;

        noElem++;
        for (int i = ind - l; i < ind; i++)
            elements[noElem][aux++] = ecuation[i];
        ind++;
        l = 0;
    }

    for (int i = 1; i <= noElem; i++)
        std::cout << elements[i] << "\n";
}