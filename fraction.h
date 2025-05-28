#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct fraction
{
    int numerator, denominator; // up, down
    fraction(int num = 0, int den = 1)
    {
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        int aux = gcd(num, den);
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
