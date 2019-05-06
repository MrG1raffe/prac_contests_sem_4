#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(void)
{
    std::vector<std::string> v;
    std::map<std::string, int> mp;
    std::string s;
    int k = 1;

    while (std::cin >> s) {
        if (*--s.end() == ':') {
            mp[s.substr(0, s.size() - 1)] = k;
        } else {
            k++;
            v.push_back(s);
        }
    }

    for (size_t i = 0; i < v.size(); i++) {
        if (mp[v[i]]) {
            std::cout << mp[v[i]] << std::endl;
        } else {
            std::cout << v[i] << std::endl;
        }
    }

    return 0;
}