#include <iostream>

void f(size_t k, size_t n)
{
    if (!k) {
        return;
    }
    for (size_t i = 0; i < k; i++) {
        std::cout << "a";
    }
    for (size_t i = 0; i < n; i++) {
        std::cout << "b";
    }
    for (size_t i = 0; i < n; i++) {
        std::cout << "c";
    }
    for (size_t i = 0; i < k; i++) {
        std::cout << "d";
    }
    std::cout << std::endl;
    f(k - 1, n + 1);
}

int main(void)
{
    int k;
    std::cin >> k;
    if (k < 4 || k % 2 == 1) {
        return 0;
    }
    f(k / 2 - 1, 1);
    return 0;
}