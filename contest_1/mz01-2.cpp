#include <iostream>

class A 
{
    int x;
    bool flag;
public:
    A() : flag(false) 
    {
        std::cin >> x;
    }
    A(const A &a) : flag(true)
    {
        std::cin >> x;
        x += a.x;
    }
    ~A() 
    {
        if (flag) {
            std::cout << x << std::endl;
        }
    }
};
