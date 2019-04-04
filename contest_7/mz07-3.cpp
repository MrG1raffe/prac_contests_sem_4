#include <iostream>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <string>

int main(void)
{
    using boost::gregorian::date;
    long long res = 0;
    std::string s1, s2;
    std::cin >> s1;
    while (std::cin >> s2) {
        date d1 = from_string(s1), d2 = from_string(s2);
        res += abs((d1 - d2).days())
        s1 = s2;
    }
    std::cout << res << std::endl;
    return 0;
}