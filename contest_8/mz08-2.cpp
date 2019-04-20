#include <iostream>
#include <ctype.h>
#include <stdio.h>

int check(void)
{
    int c;
    while (isspace(c = getchar()));
    if (c == EOF) {
        return -1;
    }
    int k = 0, m = 0;
    while (c == '0') {
        ++k;
        c = getchar();
    }
    while (c == '1') {
        ++m;
        c = getchar();
    }
    if (!k || !m) {
        while ((c == '0' || c == '1') || !isspace(c)) {
            c = getchar();
            if (c == EOF) {
                return 0;
            }
        }
        return 0;
    }
    while ((c == '0' || c == '1')) {
        int k1, m1;
        k1 = m1 = 0;
        while (c == '0') {
            ++k1;
            c = getchar();
        }
        while (c == '1') {
            ++m1;
            c = getchar();
        }
        if (k1 != k || m1 != m) {
            while ((c == '0' || c == '1') || !isspace(c)) {
                c = getchar();
                if (c == EOF) {
                    return 0;
                }
            }   
            return 0;
        }
    }
    if (c != '0' && c != '1' && !isspace(c) && c != EOF) {
        while(!isspace(c)) {
            c = getchar();
            if (c == EOF) {
                return 0;
            }
        }
        return 0;
    }
    return 1;
}

int main(void)
{
    int x;
    while ((x = check()) >= 0) {
        std::cout << x << std::endl;
    }
    return 0;
}
