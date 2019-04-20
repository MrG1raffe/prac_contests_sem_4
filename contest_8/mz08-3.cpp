#include <ctype.h>
#include <iostream>
#include <string>

int main(void)
{
    std::string left, right;
    int level = 3;
    bool empty = true, is_S = false, is_eps = false, is_right_S = false;;
    while (std::cin >> left >> right) {
        empty = false;

        if (left[0] == 'S' && left.size() == 1) {
            is_S = true;
        }

        for (size_t i = 0; i < left.size(); i++) {
            if (!isupper(left[i]) && !islower(left[i]) && !isdigit(left[i])) {
                std::cout << -1 << std::endl;
                return 0;
            }
        }
                    
        for (size_t i = 0; i < right.size(); i++) {
            if (right[i] == '_' && right.size() > 1) {
                std::cout << -1 << std::endl;
                return 0;
            }
            if (right[i] == 'S') {
                is_right_S = true;
            }
            if (!isupper(right[i]) && !islower(right[i]) && !isdigit(right[i]) && right[i] != '_') {
                std::cout << -1 << std::endl;
                return 0;
            }
        }

        bool check = false;
        for (size_t i = 0; i < left.size(); i++) {
            if (isupper(left[i])) {
                check = true;
            }
        }
        if (!check) {
            std::cout << -1 << std::endl;
            return 0;     
        }

        if (left.size() > 1) {
            if (level > 1) {
                level = 1;
            }
        }

        if (right[0] == '_') {
            if (!(left[0] == 'S' && left.size() == 1)) {
                if (level > 2) {
                    level = 2;
                }
            }
            is_eps = true;
        }

        if (left.size() > right.size()) {
            if (level > 2) {
                level = 2;
            }
        }
    }
    
    if (empty || !is_S) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (is_eps && is_right_S) {
        if (level > 2) {
            level = 2;
        }
    }

    switch(level) 
    {
    case 1:
        std::cout << 10 << std::endl;
        break;
    case 2:
        std::cout << 2 << std::endl;
        break;
    case 3:
        std::cout << 23 << std::endl;
        break;
    }
    return 0;
}