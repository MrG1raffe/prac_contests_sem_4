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


    class complex_stack 
    {
        enum { FIRST_SIZE = 16 };
        size_t capacity;
        complex *stack;
        size_t top;
        void extend(void)
        {
            capacity <<= 1;
            complex *new_stack = new complex[capacity];
            for (size_t i = 0; i < top; i++) {
                new_stack[i] = stack[i];
            }
            delete[] stack;
            stack = new_stack;
        }
    public:
        complex_stack() : capacity(FIRST_SIZE), top(0)
        {
            stack = new complex[FIRST_SIZE];
        }
        complex_stack(const complex_stack &st) 
        {
            capacity = st.capacity;
            stack = new complex[capacity];
            top = st.top;
            for(size_t i = 0; i < top; i++) {
                stack[i] = st.stack[i];
            }
        }
        ~complex_stack() 
        {
            delete[] stack;
        }
        complex_stack operator=(const complex_stack &st)
        {
            capacity = st.capacity;
            top = st.top;
            delete[] stack;
            stack = new complex[capacity];
            for (size_t i = 0; i < top; i++) {
                stack[i] = st.stack[i];
            }
            return *this;
        }
        size_t size(void) const 
        {
            return top;
        }
        complex & operator[](size_t i) const
        {
            return stack[i];
        }
        complex_stack operator<<(const complex &c) const 
        {
            complex_stack tmp = *this;
            if (top >= capacity) {
                tmp.extend();
            }
            tmp.stack[tmp.top++] = c;
            return tmp;
        }
        complex & operator+(void) const
        {
            return stack[top - 1];
        }
        complex_stack operator~(void) const
        {
            complex_stack tmp = *this;
            tmp.top--;
            return tmp;
        }
    };

    complex eval(char **args, const complex &z)
    {
        int i = 0;
        complex_stack st;
        while (args[i]) {
            char *s = args[i++];
            complex op1, op2;
            switch(s[0]) {
            case '(':
                st = st << complex(s);
                break;
            case 'z':
                st = st << z;
                break;
            case '+':
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 + op2);
                break;
            case '-':
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 - op2);
                break;
            case '*':
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 * op2);
                break;
            case '/':
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 / op2);
                break;
            case '!':
                st = st << (+st);
                break;
            case ';':
                st = ~st;
                break;
            case '~':
                op1 = +st;
                st = ~st;
                st = st << ~op1;
                break;
            case '#':
                op1 = +st;
                st = ~st;
                st = st << -op1;
                break;
            } 
        }
        return +st;
    }
    
}
