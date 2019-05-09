#include <iostream>

class S
{
    int sum;
    bool stop;
    bool empty;
public:
    S(): sum(0), stop(false), empty(false)
    {
        if (!(std::cin >> sum)) {
            empty = true;
            stop = true;
        }
    }
    S(S &&other)
    {
        sum = 0;
        stop = false;
        empty = false;
        if (!(std::cin >> sum)) {
            stop = true;
        }
        sum += other.sum;
    }
    ~S()
    {
        if (!empty && stop) {
            std::cout << sum << std::endl;
        }
    }
    operator bool() const
    {
        return !stop;
    }
};