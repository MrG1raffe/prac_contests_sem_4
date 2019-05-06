#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

class wrapper
{
    std::mutex &m;
public:
    wrapper(std::mutex &m) : m(m) { m.lock(); }
    ~wrapper() { m.unlock(); }
};

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i++) {
        threads.push_back(std::thread(f))
    }
    for (auto &t : threads)
        t.join();

    std::cout << value1 << "\n" << value2 << "\n";
    return 0;
}