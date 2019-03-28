#include <algorithm>

template <class T>
bool search(T begin, T end, int x)
{
    while (begin != end) {
        if (*begin++ == x) {
            return true;
        }
    }
    return false;
}

template <class P, class T>
T myremove(P ind_begin, P ind_end, T first, T last)
{
    int cur = 0;
    auto res = first, it = first;
    while (it != last) {
        if (!search(ind_begin, ind_end, cur)) {
            *res++ = std::move(*it);
        }
        ++it;
        ++cur;
    }
    return res;
}