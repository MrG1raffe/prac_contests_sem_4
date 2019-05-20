#include <thread>
#include <iostream>
#include <cstdlib>
#include <future>
#include <vector>
#include <utility>

std::pair<unsigned long long, unsigned long long> monte_karlo(unsigned long long its, unsigned my_num)
{
    unsigned long long in_circle = 0;
    for (unsigned long long i = 0; i < its; i++) {
        double x = 2 * (rand_r(&my_num) / ((double) RAND_MAX)) - 1;
        double y = 2 * (rand_r(&my_num) / ((double) RAND_MAX)) - 1;
        if (x * x + y * y < 1) {
            in_circle++;
        }
    }
    return std::make_pair(in_circle, its);
}

int main(int argc, char *argv[])
{
    unsigned n;
    unsigned long long its;
    sscanf(argv[1], "%u", &n);
    sscanf(argv[2], "%llu", &its);
    std::vector<std::future<std::pair<unsigned long long, unsigned long long>>> v;
    for (unsigned i = 0; i < n; i++) {
        v.push_back(std::async(std::launch::async, monte_karlo, its, i));
    }
    unsigned long long total = 0, in_circle = 0;
    for (unsigned i = 0; i < n; i++) {
        auto tmp = v[i].get();
        in_circle += tmp.first;
        total += tmp.second;
    }
    printf("%.10lf\n", 4 * ((double) in_circle) / total);
    return 0;
}
