#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

int main(void)
{
    std::multimap<char, std::string> rules;
    std::set<char> non_terms;
    std::string s2;
    char s1, c;
    while (std::cin >> s1) {
        non_terms.insert(s1);
        c = getchar();
        if (c != '\n') {
            while ((c = getchar()) != '\n') {
                s2.push_back(c);
            }
        }
        rules.insert(make_pair(s1, s2));
        s2.clear();
    }

    std::set<char> nullable;
    for (auto it: rules) {
        if (it.second == "") {
            nullable.insert(it.first);
        }
    }        
    bool is_changed = true;
    while (is_changed) {
        is_changed = false;
        for (auto it: rules) {
            std::string &s = it.second;
            bool nbl = true;
            for (size_t i = 0; i < s.size(); i++) {
                if (nullable.find(s[i]) == nullable.end()) {
                    nbl = false;
                    break;
                } 
            }
            if (nbl) {
                if (nullable.find(it.first) == nullable.end()) {
                    is_changed = true;
                    nullable.insert(it.first);
                }
            }
        }
    }
    for (auto it: non_terms) {
        std::cout << it << " ";
        bool nbl = !(nullable.find(it) == nullable.end());
        std::cout << nbl << std::endl;
    }

    std::map<char, std::set<char>> fst;
    for (auto it: rules) {
        if (!it.second.empty() && (non_terms.find(it.second[0]) == non_terms.end())) {
            fst[it.first].insert(it.second[0]);
        }
    }
    is_changed = true;
    while (is_changed) {
        is_changed = false;
        for (auto it: rules) {
            size_t i = 0;
            while (!it.second.empty() && i < it.second.size()) {
                if (non_terms.find(it.second[i]) != non_terms.end()) {
                    size_t size_before = fst[it.first].size();
                    fst[it.first].insert(fst[it.second[i]].begin(), fst[it.second[i]].end());
                    if (fst[it.first].size() > size_before) {
                        is_changed = true;
                    }
                    if (nullable.find(it.second[i]) != nullable.end()) {
                        i++;
                    } else {
                        break;
                    }
                } else {
                    size_t size_before = fst[it.first].size();
                    fst[it.first].insert(it.second[i]);
                    if (fst[it.first].size() > size_before) {
                        is_changed = true;
                    }
                    break;
                }
            }
        }
    }
    for (auto it: non_terms) {
        std::cout << it << " ";
        for (auto it2: fst[it]) {
            std::cout << it2;
        }
        std::cout << std::endl;
    }

    std::map<char, std::set<char>> follow;
    for (auto it: rules) {
        if (!it.second.empty()) {
            for (size_t i = 0; i < it.second.size() - 1; i++) {
                if (non_terms.find(it.second[i]) != non_terms.end()) {
                    size_t j = 1;
                    while (i + j < it.second.size()) {
                        if (non_terms.find(it.second[i + j]) != non_terms.end()) {
                            follow[it.second[i]].insert(fst[it.second[i + j]].begin(), fst[it.second[i + j]].end());
                            if (nullable.find(it.second[i + j]) != nullable.end()) {
                                j++;
                            } else {
                                break;
                            }
                        } else {
                            follow[it.second[i]].insert(it.second[i + j]);
                            break;
                        }
                    }
                }
            }
        }
    }
    is_changed = true;
    while (is_changed) {
        is_changed = false;
        for (auto it: rules) {
            if (!it.second.empty()) {
                char c = it.second[it.second.size() - 1];
                if (non_terms.find(c) != non_terms.end()) {
                    size_t size_before = follow[c].size();
                    follow[c].insert(follow[it.first].begin(), follow[it.first].end());
                    if (follow[c].size() > size_before) {
                        is_changed = true;
                    }
                }
            }
        }
    }
    is_changed = true;

    while (is_changed) {
        is_changed = false;
        for (auto it: rules) {
            if (!it.second.empty()) {
                size_t i;
                for (i = it.second.size() - 1; i >= 0; --i) {
                    if (non_terms.find(it.second[i]) == non_terms.end()) {
                        break;
                    }
                    size_t size_before = follow[it.second[i]].size();
                    follow[it.second[i]].insert(follow[it.first].begin(), follow[it.first].end());
                    if (follow[it.second[i]].size() > size_before) {
                        is_changed = true;
                    }
                    if (nullable.find(it.second[i]) == nullable.end()) {
                        break;
                    }
                }
            }
        }
    }

    for (auto it: non_terms) {
        std::cout << it << " ";
        for (auto it2: follow[it]) {
            std::cout << it2;
        }
        std::cout << std::endl;
    }

    return 0;
}