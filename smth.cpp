#include <iostream>
#include <typeinfo>

using namespace std;

struct A {
    virtual void h(int& a)
    {
        a++;
        cout << "h_from_A\n";
    }
    virtual int t() const
    {
        cout << "t_from_A\n ";
        return 0;
    }
};
struct S : A {
    int h(long& a)
    {
        a++;
        cout << "h_from_S\n";
        return 0;
    }
    int t()
    {
        cout << "t_from_S\n ";
        return 0;
    }
};

int main()
{
    int n = 5;
    const A a1;
    S s1;
    A* p = &s1;
    a1.t();
    p->h(n);
    p->t();
    cout << "n = " << n << endl;
    return 0;
}