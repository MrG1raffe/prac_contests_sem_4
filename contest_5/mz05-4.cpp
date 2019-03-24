#include <cmath>
#include <string>
#include <sstream>

class Rectangle: public Figure
{
    double a, b;
public:
    Rectangle(double x = 0, double y = 0): a(x), b(y) {}
    double get_square() const override
    {
        return a * b;
    }
    static Rectangle *make(const std::string &s)
    {
        double x, y;
        std::stringstream stream(s);
        stream >> x >> y;
        Rectangle *p = new Rectangle(x, y);
        return p;
    }
};

class Square: public Figure
{
    double a;
public:
    Square(double x = 0): a(x) {}
    double get_square() const override
    {
        return a * a;
    }
    static Square *make(const std::string &s)
    {
        double x;
        std::stringstream stream(s);
        stream >> x;
        Square *p = new Square(x);
        return p;
    }
};

class Circle: public Figure
{
    double r;
public:
    Circle(double x = 0): r(x) {}
    double get_square() const override
    {
        return M_PI * r * r;
    }
    static Circle*make(const std::string &s)
    {
        double x;
        std::stringstream stream(s);
        stream >> x;
        Circle *p = new Circle(x);
        return p;
    }
};
