#include <iostream>
#include <iomanip>
#include <math.h>

int main(void)
{
    double m = 0, m2 = 0;
    double x;
    int n = 0;
    while(std::cin >> x) {
        n++;
        m += x;
        m2 += x * x;
    }
    m /= n;
    double sigma = sqrt(m2 / n - m * m);
    std::cout << std::setprecision(10) << m << std::endl << sigma << std::endl;
    return 0;
}
