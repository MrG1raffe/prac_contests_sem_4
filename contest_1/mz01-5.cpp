#include <string>
#include <iostream>

class Rational 
{
    int a, b;
    void reduce(void) 
    {
        if (b < 0 && a < 0) {
            a = -a;
            b = -b;
        }
        int max = (abs(a) > abs(b)) ? abs(a) : abs(b);
        int min = (abs(a) < abs(b)) ? abs(a) : abs(b);
        if (!min) {
            b = 1;
            return;
        }
        int gcd = max % min;
        while (gcd) {
            max = min;
            min = gcd;
            gcd = max % min;
        }
        gcd = min;
        a /= gcd;
        b /= gcd;
    }
public:
    Rational(int x = 0, int y = 1) : a(x), b(y) 
    {
        reduce();
    }
    Rational & Add(const Rational &q)
    {
        a = a * q.b + q.a * b;
        b = b * q.b;
        reduce();
        return *this;
    }
    Rational & Substract(const Rational &q)
    {
        a = a * q.b - q.a * b;
        b = b * q.b;
        reduce();
        return *this;
    }
    Rational & Multiply(const Rational &q)
    {
        a = a * q.a;
        b = b * q.b;
        reduce();
        return *this;
    }
    Rational & Divide(const Rational &q)
    {
        int aa = q.a, bb = q.b;
        a = a * bb;
        b = b * aa;
        reduce();
        return *this;
    }
    bool EqualTo(const Rational &w) const
    {
        return (a == w.a && b == w.b) || (a == -w.a && b == -w.b);
    }
    int CompareTo(const Rational &w) const
    {
        return ((b > 0 && w.b > 0) || (b < 0 && w.b < 0)) ? a * w.b - w.a * b : w.a * b - a * w.b;
    }
    bool IsInteger(void) const
    {
        return b == 1 || b == -1;
    }
    std::string ToString(void) const
    {
        std::string s1 = std::to_string(a), s2 = std::to_string(b);
        return s1 + ":" + s2;
    }
};
