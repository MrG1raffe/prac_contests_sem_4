/*
S 1A0<0>
A 1A0<0>|<1>0B1<0>
B <1>0B1<0>|eps
*/

#include <iostream>
#include <ctype.h>

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
    while(1) {
        gc();
        while (isspace(c)) {
            gc();
        }
        if (c == EOF) {
            break;
        }
        gc();
        A();
        std::cout << 0 << std::endl;
    }
    return 0;
}