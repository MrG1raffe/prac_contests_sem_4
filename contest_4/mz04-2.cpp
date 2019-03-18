template <class T, class P>
T myfilter(const T &obj, P func)
{
    T new_obj;
    auto p = obj.begin();
    while (p != obj.end())
    {
        if (func(*p)) {
            new_obj.insert(new_obj.end(), *p);
        }
        ++p;
    }
    return new_obj;
}
