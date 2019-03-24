template <class T>
myremove(T ind_begin, T ind_end, T first, T last)
{
    std::sort(ind_begin, ind_end);
    while(ind_begin != ind_end && *ind_begin < 0) {
        ind_begin++;
    }

}
