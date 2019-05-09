#include <iostream>

struct A
{
    private:
        int num = 0;
        bool flag;
    public:
        A() : flag(false)
        {
            std::cin >> num;
        }
        A(const A& a) : flag(true)
        {
            std::cin >> num;
            num += a.num;
        }
        ~A()
        {
            if (flag) {
                std::cout << num << std::endl;
            }
        }
};