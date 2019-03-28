#include <iostream>
#include <string>

void read_string(void)
{
    class Cl 
    {
    public:
        bool flag;
        std::string s;
        ~Cl()
        {
            if (flag) {
                std::cout << s << std::endl;
            }
        }
    };
    Cl tmp;
    if (std::cin >> tmp.s) {
        tmp.flag = true;
    } else {
        tmp.flag = false;
        throw 1;
    }
    read_string();
}

int main(void)
{
    try {
        read_string();
    } catch(int) {
    }
    return 0;
}