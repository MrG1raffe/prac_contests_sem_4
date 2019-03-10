#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
    std::string s;
    while (std::cin >> s) {
        std::string tmp = s;
        std::reverse(tmp.begin(), tmp.end());
        for (unsigned long i = 0; i < s.size(); i++) {
            if (std::equal(tmp.begin(), tmp.end() - i, s.begin() + i)) {
                std::cout << s.substr(i) << std::endl;
                break;
            }
        }
    }
    return 0;
}
