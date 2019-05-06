#include <vector>
#include <string>
#include <map>
#include <iostream>


bool search(const std::string &s, const std::vector<std::string> &v)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == s) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    std::map<std::string, std::string> rules;
    std::string s1, s2;
    char c;
    while (1) {
        std::cin >> s1;
        if (s1 == "END") {
            break;
        }

        std::cin >> c >> s2;
        rules[s1 + " " + c] = s2;
    }

    std::vector<std::string> terminals;
    while (1) {
        std::cin >> s1;
        if (s1 == "END") {
            break;
        }

        terminals.push_back(s1);
    }

    std::string cur;
    std::cin >> cur;

    std::string input;
    std::cin >> input;

    size_t cnt = 0;
    bool ok = true;

    while (1) {
        if (cnt == input.size()) {
            break;
        }
        c = input[cnt];
        std::string tmp = rules[cur + " " + c];
        if (tmp.empty()) {
            ok = false;
            break;
        }
        cur = tmp;
        cnt++;
    }

    if (!search(cur, terminals)) {
        ok = false;
    }

    std::cout << ok << std::endl << cnt << std::endl << cur << std::endl;
    return 0;
}