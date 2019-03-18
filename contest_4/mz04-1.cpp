template <typename T>
typename T::value_type process(const T &k)
{
    typename T::value_type res = typename T::value_type();
    typename T::const_iterator p = k.end(), first = k.begin();
    if (p == first) {
        return res;
    }
    --p;
    res += *p;
    if (p == first) {
        return res;
    }
    for (int i = 0; i < 2; i++) {
        --p;
        if (p == first) {
            break;
        }
        --p;
        res += *p;
        if (p == first) {
            break;
        }
    }
    return res;
}
