#include <vector>
#include <functional>

template <class T, class P>

void myapply(T first, T last, P func)
{
    while (first != last) {
        func(*first);
        first++;
    }
}

template <class T, class P>

std::vector<std::reference_wrapper<typename T::value_type>> myfilter2(T first, T last, P func)
{
    std::vector<std::reference_wrapper<typename T::value_type>> res;
    while (first != last) {
        if (func(*first)) {
            res.insert(res.end(), std::reference_wrapper<typename T::value_type>(*first));
        }
        first++;
    }
    return res;
}

template <class T, class P>

void myapply(T *first, T *last, P func)
{
    while (first != last) {
        func(*first);
        first++;
    }
}

template <class T, class P>

std::vector<std::reference_wrapper<T>> myfilter2(T *first, T *last, P func)
{
    std::vector<std::reference_wrapper<T>> res;
    while (first != last) {
        if (func(*first)) {
            res.insert(res.end(), std::reference_wrapper<T>(*first));
        }
        first++;
    }
    return res;
}
