#include <iostream>

/*
При k = 0 - сложение чисел a и b
При k = 1 - уиножение (сложение a + .. + a  b раз)
При k = 2 - степень (умножение a * ... * a  b раз)
При k = 3 - a ^ ... ^ a  b раз
...
*/

class Result
{
public:
    long long res;
    Result(long long t): res(t) {}
};

void func(long long a, long long b, unsigned k)
{
    if (!k) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    } 
    long long tmp;
    try {
        func(a, b - 1, k);
    } catch(Result &ex) {
        tmp = ex.res;
    }
    try {
        func(a, tmp, k - 1);
    } catch(Result &ex) {
        tmp = ex.res;
    }
    throw Result(tmp);
}

int main(void)
{
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch(Result &ex) {
            std::cout << ex.res << std::endl;
        }
    }
    return 0;
}