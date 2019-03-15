#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(void)
{
    std::vector<double> sample;
    double tmp;
    while (std::cin >> tmp) {
        sample.push_back(tmp);
    }

    size_t n = sample.size();
    size_t tenth = n / 10;
    sample.erase(sample.begin(), sample.begin() + tenth);
    sample.erase(sample.end() - tenth, sample.end());
    n -= 2 * tenth;

    std::sort(sample.begin(), sample.end());
    tenth = n / 10;
    sample.erase(sample.begin(), sample.begin() + tenth);
    sample.erase(sample.end() - tenth, sample.end());
    n -= 2 * tenth;

    struct Sum
    {
        double res;
        Sum(): res(0) {}
        void operator()(double x) { res += x; }
    };

    Sum s = std::for_each(sample.begin(), sample.end(), Sum());
    std::cout << std::fixed << std::setprecision(10) << s.res / n << std::endl;
}
