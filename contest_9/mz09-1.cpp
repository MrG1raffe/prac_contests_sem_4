/*
Тип языка 0

S = aXPQ
P = YXP | ε
Q = UVQ | ε
aY = aa
aU = a0
0U = 00
0X = 0b
bX = bb
bV = b1
1V = 11
XY = YX
UY = YU
VY = YV
XU = UX
VU = UV
VX = XV
*/
#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    int m, n, m1, n1;
    while (std::cin >> s) {
        m = n = 0;
        unsigned long i = 0;
        while (i < s.size() && s[i] == 'a') {
            i++;
            m++;
        }
        while (i < s.size() && s[i] == '0') {
            i++;
            n++;
        }
        if (!m || !n) {
            std::cout << 0 << std::endl;
            continue;
        }
        m1 = n1 = 0;
        while (i < s.size() && s[i] == 'b') {
            i++;
            m1++;
        }
        while (i < s.size() && s[i] == '1') {
            i++;
            n1++;
        }
        if (i != s.size() || m1 != m || n1 != n) {
            std::cout << 0 << std::endl;
            continue;
        }
        std::cout << 1 << std::endl;
    } 
    return 0;  
}