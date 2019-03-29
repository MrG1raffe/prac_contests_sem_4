#include <cmath>
#include <string>
#include <sstream>

class Figure
{
public:
    virtual double get_square() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~Figure() {}
};


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
    std::string to_string(void) const
    {
        return std::to_string(a) + " " + std::to_string(b);
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
    std::string to_string(void) const
    {
        return std::to_string(a);
    }
};

class Circle: public Figure
{
    double r;
public:
    Circle(double x = 0): r(x) {}
    double get_square() const override
    {
        return 3.14 * r * r;
    }
    static Circle*make(const std::string &s)
    {
        double x;
        std::stringstream stream(s);
        stream >> x;
        Circle *p = new Circle(x);
        return p;
    }
    std::string to_string(void) const
    {
        return std::to_string(r);
    }
};




#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Factory
{
    static Factory *instance;
    Factory() {}
    Factory(const Factory &x) {}
public:
    static Factory *factory_instance(void)
    {
        if (!instance) {
            return new Factory();
        } 
        return instance;
    }
    Figure *make(char type, const std::string &s)
    {
        if (type == 'R') {
            return Rectangle::make(s);
        }
        if (type == 'S') {
            return Square::make(s);
        }
        if (type == 'C') {
            return Circle::make(s);
        }
        return nullptr;
    }
};

Factory* Factory::instance = nullptr;

bool comp(Figure *f1, Figure *f2)
{
    return (f1->get_square() < f2->get_square());
}

int main(void)
{
    std::vector<Figure*> v;
    std::string input;
    Factory *fact = Factory::factory_instance();
    while (1) {
        std::getline(std::cin, input);
        if (input.begin() == input.end()) {
            break;
        }
        std::istringstream stream(input);
        char type;
        stream >> type;
        int cnt = 1;
        auto it = input.begin();
        while (*it++ != type) {
            cnt++;
        }
        input.erase(0, cnt);
        v.push_back(fact->make(type, input));
    }
    std::stable_sort(v.begin(), v.end(), comp);
    for (Figure *f: v) {
        std::cout << f->to_string() << std::endl;
        if (f) {
            delete f;
        }
    }
    if (fact) {
        delete fact;
    }
    return 0;
}