#include <iostream>
#include <vector>

void process(const std::vector<int> &v1, std::vector<int> &v2, int step)
{
    auto p2 = v2.begin();
    for (auto p1 = v1.begin(); p2 != v2.end() && p1 < v1.end(); p2++) {
        *p2 = *p1;
        if (v1.end() - p1 < step) {
            break;
        }
        p1 += step;
    }
    for (auto rp = v2.rbegin(); rp != v2.rend(); rp++) {
        std::cout << *rp << std::endl;
    }
}
