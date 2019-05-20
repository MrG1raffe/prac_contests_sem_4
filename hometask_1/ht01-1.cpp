#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::mutex m;
double arr[3];

enum {
    SIZE = 3,
    AMOUNT = 1000000
};

void f(int x)
{
    for (int i = 0; i < AMOUNT; i++) {
        m.lock();
        arr[x] += 100 * (x + 1);
        arr[(x + 1) % 3] -= (x + 1) * 100 + 1;
        m.unlock();
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i++) {
        threads.push_back(std::thread(f, i));
    }
    for (auto &t : threads) {
        t.join();
    }
    for (int i = 0; i < 3; i++) {
        printf("%.10g\n", arr[i]);
    }
    return 0;
}