#include "translateProb.h"
#include "config.h"
#include <iostream>
#include <map>

struct elGr
{
    char *el;
    int coef;
};

extern char **elements;
extern int noElem;

extern **mat;
int indexElem;

char diffEl[mxN][3];
int noDifElem = 0;

std::map<char *, int> coefElemSubst[mxN];

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

bool existingElement(char *el)
{
    bool exista = false;
    for (int i = 1; i <= noDifElem; i++)
    {
        if (el[0] == diffEl[i][0])
        {
            if (el[1] == '\0')
                return true;

            if (el[1] == diffEl[i][1])
                return true;
        }
    }

    return false;
}

void addElement(char *el)
{
    noDifElem++;
    int j;
    for (j = 0; j <= 2 && el[j] != '\0'; j++)
        diffEl[noDifElem][j] = el[j];

    diffEl[noDifElem][j] = '\0';
}

void translate()
{
    for (int i = 1; i <= noElem; i++)
    {
        indexElem = 0;
        while (elements[i][indexElem] != '\0')
        {
            elGr aux = computeElem(i);
            coefElemSubst[i][aux.el] = aux.coef;

            if (!existingElement(aux.el))
                addElement(aux.el);
        }
    }

    for (int i = 1; i <= noElem; i++)
    {
        for (auto x : coefElemSubst[i])
            std::cout << x.first << " ";
        std::cout << "\n";
    }
}