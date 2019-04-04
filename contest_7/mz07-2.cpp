#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    std::cin >> s;
    size_t i = 0;
    int flag = 0;
    while (i < s.size()) {
        if (s[i++] == '1') {
            flag ^= 1;
        }
    }
    i = 0;
    while (i < s.size() && s[i] != '1') {
        i++;
    }
    if (i < s.size() && flag) {
        s[i] = '0';
    }
    std::cout << s << std::endl;
    return 0;
}