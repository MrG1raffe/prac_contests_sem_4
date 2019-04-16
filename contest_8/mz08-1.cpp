#include <iostream>
#include <string>

int check(const std::string &s)
{
    bool flag = false;
    unsigned long i = 0;
    while (i < s.size()) {
        if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4') {
            if (flag && (s[i] == '3' || s[i] == '4')) {
                return 0;
            }
            if (s[i] == '1' || s[i] == '2') {
                flag = true;
            }
            i++;
        } else {
            return 0;
        }
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