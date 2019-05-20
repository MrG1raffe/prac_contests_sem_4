#include <iostream>
class S
{
    int res;
    bool is_exit, is_print;
public:
    S(): res(0), is_exit(false), is_print(false)
    {
        if (!(std::cin >> res)) {
            is_exit = true;
        }
    }
    S(S &&x): res(0)
    {
        if (!(std::cin >> res)) {
            is_print = true;
            is_exit = true;
        } else {
            is_print = is_exit = false;
        }
        res += x.res;
    }
    ~S()
    {
        if (is_print) {
            std::cout << res << std::endl;
        }
    }
    explicit operator bool() const
    {
        return !is_exit;
    }
};
