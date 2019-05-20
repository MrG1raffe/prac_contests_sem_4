#include <mutex>
#include <thread>
#include <iostream>
#include <future>
#include <vector>

bool prime(unsigned long long x)
{
    if (x == 1 || x == 0) {
        return false;
    }
    for (unsigned long long i = 2; i * i <= x; i++) {
        if (!(x % i)) {
            return false;
        }
    }
    return true;
}

void f(unsigned long long low, unsigned long long high, unsigned count,
                std::vector<std::promise<unsigned long long>> &pr)
{
    size_t ind = 0;
    for (unsigned long long i = low; i <= high; i++) {
        if (prime(i)) {
            pr[ind++].set_value(i);
        }
        if (ind == count) {
            break;
        }
    }
    try {
        if (ind < count) {
            uint64_t exc = high;
            throw exc;
        }
    } catch (const uint64_t &x) {
        pr[ind].set_exception(std::make_exception_ptr(x));
    }
}

int main()
{
    unsigned long long low, high;
    unsigned count;
    std::cin >> low >> high >> count;
    std::vector<std::promise<unsigned long long>> pr(count);
    std::vector<std::future<unsigned long long>> ft(count);
    for (unsigned i = 0; i < count; i++) {
        ft[i] = pr[i].get_future();
    }
    std::thread t(f, low, high, count, std::ref(pr));
    try {
    for (unsigned i = 0; i < count; i++) {
            std::cout << ft[i].get() << std::endl;
        }
    } catch (const uint64_t &x) {
        std::cout << x << std::endl;
    }
    t.join();
    return 0;
}
