#include "translateProb.h"
#include <iostream>

struct elGr
{
    char *el;
    int coef;
};

extern char **elements;
extern int noElem;

extern **mat;
int indexElem;

elGr computeElem(int ind)
{
    // TO DO: verify if next character is another element
    char *elem = new char;
    int coeficient = 0, indAux = 0;
    while ((elements[ind][indexElem] >= 'a' && elements[ind][indexElem] <= 'z') || (elements[ind][indexElem] >= 'A' && elements[ind][indexElem] <= 'Z') && elements[ind][indexElem] != '\0')
        elem[indAux++] = elements[ind][indexElem++];

    elem[indAux++] = '\0';

    while (elements[ind][indexElem] >= '0' && elements[ind][indexElem] <= '9' && elements[ind][indexElem] != '\0')
        coeficient = coeficient * 10 + (elements[ind][indexElem++] - '0');

    if (coeficient == 0)
        coeficient = 1;
    return elGr{elem, coeficient};
}

void translate()
{
    for (int i = 1; i <= noElem; i++)
    {
        indexElem = 0;
        while (elements[i][indexElem] != '\0')
        {
            elGr aux = computeElem(i);
            std::cout << aux.el << " " << aux.coef << "\n";
        }

        std::cout << "\n";
    }
}