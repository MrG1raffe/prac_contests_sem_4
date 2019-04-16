#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp> 
#include <string>

using boost::gregorian::date;

int main(void)
{
    long long res = 0;
    int y1, y2, m1, m2, d1, d2;
    char tmp;
    std::cin >> y1 >> tmp >> m1 >> tmp >> d1;
    while (std::cin >> y2 >> tmp >> m2 >> tmp >> d2) {
        date dt1 = date(y1, m1, d1);
        date dt2 = date(y2, m2, d2);
        res += abs((dt1 - dt2).days());
        y1 = y2;
        m1 = m2;
        d1 = d2;
    }
    std::cout << res << std::endl;
    return 0;
}