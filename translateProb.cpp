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
extern int noElem, *firstPart, n, m;

extern **mat;
int indexElem;

char diffEl[mxN][3];
int noDifElem = 0;

std::map<int, int> coefElemSubst[mxN];

int toKey(const char *el)
{
    if (el[1] == '\0')
        return el[0] * 1000;
    return el[0] * 1000 + el[1];
}

elGr computeElem(int ind)
{
    // TO DO: verify if next character is another element
    // TO DO: verify if
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
            if (firstPart[i] == 1)
                coefElemSubst[i][toKey(aux.el)] = aux.coef;
            else
                coefElemSubst[i][toKey(aux.el)] = -aux.coef;

            if (!existingElement(aux.el))
                addElement(aux.el);
        }
    }

    for (int i = 1; i <= noElem; i++)
        for (int j = 1; j <= noDifElem; j++)
            mat[j][i] = coefElemSubst[i][toKey(diffEl[j])];

    n = noDifElem;
    m = noElem;
}