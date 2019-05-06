#include <iostream>
#include <vector>

int main(void)
{
    std::vector<std::string> v;
    std::string s1, s2, s = "0";
    char c;
    while (std::cin >> c) {
        s[0] = c;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            s2 = v[v.size() - 1];
            s1 = v[v.size() - 2];
            v.pop_back();
            v[v.size() - 1] = "(" + s1 + s + s2 + ")"; 
        } else {
            v.push_back(s);
        }
    }
    std::cout << v[v.size() - 1] << std::endl;
    return 0;
}