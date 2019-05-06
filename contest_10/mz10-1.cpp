#include <iostream>
#include <string>

bool check(const std::string &s) 
{
    bool flag = false;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] < '1' || s[i] > '4') {
            return false;
        }
        if (s[i] == '1' || s[i] == '2') {
            flag = true;
        }
        if (flag && (s[i] == '3' || s[i] == '4')) {
            return false;
        } 
    }
    return true;
}

std::string &next(std::string &s, int k) 
{
    for (int i = k - 1; i >= 0; i--) {
        if (s[i] == '4') {
            s[i] = '1';
        } else {
            ++s[i];
            return s;
        }
    }
    return s;
}

int main(void)
{
    int k;
    std::cin >> k;
    std::string s = "", last = "";
    for (int i = 0; i < k; i++) {
        s += "1";
        last += "4";
    }
    while (1) {
        if (check(s)) {
            std::cout << s << std::endl;
            if (s == last) {
                break;
            }
        }
        s = next(s, k);
    }
    
    return 0;
}