#include <typeinfo>

struct A {
    void f() {}
};

struct B: A {
    virtual void f() {}
};

int main()
{
    A *pa;
    B b, *pb;
    pa = &b;
    pb = dynamic_cast<B*>(pa);
}