#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

double *accounts;
std::mutex *m;

void f(unsigned thread_num, unsigned iterations, unsigned ind1, unsigned ind2, double dif1, double dif2)
{
    for (unsigned i = 0; i < iterations; i++) {
        if (ind1 > ind2) {
            m[ind1].lock();
            m[ind2].lock();
            accounts[ind1] += dif1;
            accounts[ind2] += dif2;
            m[ind1].unlock();
            m[ind2].unlock();
        } else {
            m[ind2].lock();
            m[ind1].lock();
            accounts[ind1] += dif1;
            accounts[ind2] += dif2;
            m[ind2].unlock();
            m[ind1].unlock();
        }
    }
}

int main(void)
{
    unsigned acc_count, thr_count;
    std::cin >> acc_count >> thr_count;
    accounts = new double[acc_count];
    m = new std::mutex[acc_count];
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < thr_count; i++) {
        unsigned iterations, ind1, ind2;
        double dif1, dif2;
        std::cin >> iterations >> ind1 >> dif1 >> ind2 >> dif2;
        threads.push_back(std::thread(f, i, iterations, ind1, ind2, dif1, dif2));
    }
    for (unsigned i = 0; i < thr_count; i++) {
        threads[i].join();
    }
    for (unsigned i = 0; i < acc_count; i++) {
        printf("%.10g\n", accounts[i]);
    }
    delete[] accounts;
    delete[] m;
    return 0;
}
