#include <iostream>
#include "input.h"
#include <map>

extern **mat;

const int mxC = 100001;

char elements[101][mxC];
bool firstPart[mxC];
int noElem = 0;
char ecuation[mxC];

bool iCanContinue(int i)
{
    if (ecuation[i] == ' ')
        return true;
    return (ecuation[i] != '+' && ecuation[i] != '=');
}

void input()
{
    int ind = 1, l = 1;
    bool inFirstPart = true;
    std::cout << "Introdu ecuația pe care vrei sa o egalez: ";
    std::cin.getline(ecuation, mxC - 1);

    while (ecuation[ind] != '\0')
    {
        int aux = 0;
        while (iCanContinue(ind) && ecuation[ind] != '\0')
            l++, ind++;

        noElem++;
        firstPart[noElem] = inFirstPart;
        for (int i = ind - l; i < ind; i++)
        {
            if (ecuation[i] == ' ')
                continue;
            elements[noElem][aux++] = ecuation[i];
        }

        if (ecuation[ind] == '=')
            inFirstPart = false;
        ind++;
        l = 0;
    }

    for (int i = 1; i <= noElem; i++)
        if (true)
            std::cout << elements[i] << "\n";
}