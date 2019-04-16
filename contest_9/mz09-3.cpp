#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string s;

int comp(const void *a, const void *b) 
{
    return s.substr(*((int *) a), s.size() - *((int *) a)) > s.substr(*((int *) b), s.size() - *((int *) b));
}

int main(void)
{
    getline(std::cin, s);
    int v[32768];
    auto first = s.begin(), last = s.end();
    while(isspace(*(last - 1))) {
        last--;
    }
    s = std::string(first, last);
    for (size_t i = 0; i < s.size(); i++) {
        v[i] = i;
    }
    std::qsort(v, (int) s.size(), sizeof(int), comp);
    for (size_t i = 0; i < s.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}