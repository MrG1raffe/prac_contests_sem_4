#include <iostream>

char c;

void gc()
{
    c = getchar();
}

void B(void)
{
    if (c == '1') {
        return;
    } 
    std::cout << 1;
    gc();
    B();
    gc();
    std::cout << 0;
}

void A(void)
{
    if (c == '1') {
        gc();
        A();
        gc();
        std::cout << 0;
    } else if (c == '0') {
        std::cout << 1;
        gc();
        B();
        gc();
        std::cout << 0;
    }
}


int main(void)
{
    gc();
    gc();
    A();
    std::cout << 0;
    return 0;
}