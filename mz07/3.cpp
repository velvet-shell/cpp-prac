#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main(void) {
    using namespace boost::gregorian;

    date a, b;
    date_duration dur;
    int year, month, day;
    unsigned long long sum = 0;

    scanf("%d-%d-%d", &year, &month, &day);
    b = date(year, month, day);

    while (scanf("%d-%d-%d", &year, &month, &day) == 3) {
        a = date(year, month, day);
        dur = b - a;
        sum += abs(dur.days());
        b = date(year, month, day);
    }
    std::cout << sum << std::endl; 
    return 0;
}