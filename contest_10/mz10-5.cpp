#include <vector>
#include <string>
#include <map>
#include <iostream>

std::map<std::string, std::vector<std::string>> rules;
std::vector<std::string> terminals;
std::string input;

std::pair<bool, size_t> check(const std::string &cur, size_t cnt)
{
    std::string s;
    if (cnt == input.size()) {
        for (size_t i = 0; i < terminals.size(); i++) {
            if (cur == terminals[i]) {
                return std::pair<bool, size_t>(true, cnt);
            }
        }
        return std::pair<bool, size_t>(false, cnt);
    }

    std::pair<bool, size_t> best, tmp;

    best.first = false;
    best.second = cnt;

    for (size_t i = 0; i < rules[cur + " eps"].size(); i++) {
        if (rules[cur + " eps"][i] != cur) {
            tmp = check(rules[cur + " eps"][i], cnt);
            if (tmp.first > best.first || (!best.first && tmp.second > best.second)) {
                best = tmp;
            }            
        }
    }

    for (size_t i = 0; i < rules[cur + " " + input[cnt]].size(); i++) {
        size_t cnt_1 = cnt;
        tmp = check(rules[cur + " " + input[cnt_1]][i], ++cnt);
        if (tmp.first > best.first || (!best.first && tmp.second > best.second)) {
            best = tmp;
        }
    }

    return best;
}

int main(void)
{
    std::string s1, s2, c;
    while (1) {
        std::cin >> s1;
        if (s1 == "END") {
            break;
        }

        std::cin >> c >> s2;
        rules[s1 + " " + c].push_back(s2);
    }

    while (1) {
        std::cin >> s1;
        if (s1 == "END") {
            break;
        }

        terminals.push_back(s1);
    }

    std::string cur;
    std::cin >> cur;

    std::cin >> input;

    std::pair<bool, size_t> res = check(cur, 0);

    std::cout << res.first << std::endl << res.second << std::endl;
    return 0;
}