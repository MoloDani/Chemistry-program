#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include "det.h"

struct fraction
{
    int numerator, denominator; // up, down
    fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    fraction(int num)
    {
        numerator = num;
        denominator = 1;
    }

    fraction(int num, int den)
    {
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        int aux = gcd(num, den);
        if (aux == 0)
            aux = 1;
        denominator = den / aux;
        numerator = num / aux;
    }

    fraction operator*(const fraction &other) const
    {
        return fraction(numerator * other.numerator, denominator * other.denominator);
    }
};

inline std::ostream &operator<<(std::ostream &out, const fraction &f)
{
    out << f.numerator;
    if (f.denominator != 1)
        out << "/" << f.denominator;
    return out;
}

#endif
