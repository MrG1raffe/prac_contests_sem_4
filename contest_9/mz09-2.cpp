#include <iostream>
#include <string>

int check(const std::string &s) 
{
    if (s.size() < 3 || s[s.size() - 3] == '0') {
        return 0;
    }
    size_t i = s.size();
    while (i > 0) {
        if (s[i - 1] != '0' && s[i - 1] != '1') {
            return 0;
        }
        i--;
    }
    return 1;
}

int main(void)
{
    std::string s;
    while (std::cin >> s) {
        std::cout << check(s) << std::endl;
    }
    return 0;
}