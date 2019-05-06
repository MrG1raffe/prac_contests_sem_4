#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

struct Rule {
    bool checked;
    char left;
    std::string right;
    Rule(char ch = 0, const std::string &s = ""): left(ch), right(s) { checked = false; }
};

bool search(char c, const std::vector<char> &v) 
{
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == c) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    std::vector<Rule> rules;
    char c;
    std::string s;
    while (std::cin >> c >> s) {
        rules.push_back(Rule(c, s));
    }
    std::vector<char> reachable;
    reachable.push_back('S');
    bool is_changed = true;
    while (is_changed) {
        is_changed = false;
        for (size_t i = 0; i < rules.size(); i++) {
            if (search(rules[i].left, reachable) && !rules[i].checked) {
                for (size_t j = 0; j < rules[i].right.size(); j++) {
                    if (isupper(rules[i].right[j]) && !search(rules[i].right[j], reachable)) {
                        is_changed = true;
                        reachable.push_back(rules[i].right[j]);
                    }
                }
                rules[i].checked = true;
            }
        }
    }
    for (size_t i = 0; i < rules.size(); i++) {
        if (rules[i].checked) {
            std::cout << rules[i].left << ' ' << rules[i].right << std::endl;
        }
    }
    return 0;
}