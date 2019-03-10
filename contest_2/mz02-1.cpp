#include <stdio.h>
#include <cmath>

namespace numbers
{
    class complex
    {
        double re, im;
    public:
        complex(double x = 0, double y = 0) : re(x), im(y) {}
        explicit complex(const char *str)
        {
            sscanf(str, "(%lf,%lf)", &re, &im);
        }
        double get_re(void) const
        {
            return re;
        }
        double get_im(void) const
        {
            return im;
        }
        double abs2(void) const
        {
            return re * re + im * im;
        }
        double abs(void) const
        {
            return sqrt(re * re + im * im);
        }
        void to_string(char *buf, size_t size) const
        {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }
        friend complex operator+(const complex &a, const complex &b);
        friend complex operator-(const complex &a, const complex &b);
        friend complex operator*(const complex &a, const complex &b);
        friend complex operator/(const complex &a, const complex &b);
        friend complex operator~(const complex &a);
        friend complex operator-(const complex &a);
    };

    complex operator~(const complex &a) 
    {
        return complex(a.re, -a.im);
    }
    complex operator-(const complex &a) 
    {
        return complex(-a.re, -a.im);
    }
    complex operator+(const complex &a, const complex &b)
    {
        return complex(a.re + b.re, a.im + b.im);
    }
    complex operator-(const complex &a, const complex &b)
    {
        return complex(a.re - b.re, a.im - b.im);
    }
    complex operator*(const complex &a, const complex &b) 
    {
        return complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re); 
    }
    complex operator/(const complex &a, const complex &b)
    {
        return complex((a.re * b.re + a.im * b.im) / b.abs2(), (a.im * b.re - a.re * b.im) / b.abs2());
    }
}
