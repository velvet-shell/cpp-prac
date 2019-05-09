#include <cstdint>
#include <iostream>

/*
func(a, b, k) - гипероператор (k + 1)-го порядка с аргументами a и b
k == 0: сложение: a + b
k == 1: умножение: a * b
k == 2: возведение в степень: a ^ b
...  
*/

class Result
{
    int64_t res;
public:
    Result(int64_t a): res(a) {};
    int64_t get_result(void) {
        return res;
    }
};

void func(int64_t a, int64_t b, int32_t k)
{
    if (!k) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    }
    int64_t tmp = 0;
    try {
        func(a, b - 1, k);
    } catch (Result &ex) {
        tmp = ex.get_result();
    }
    try {
        func(a, tmp, k - 1);
    } catch (...) {
        throw;
    }
}

int main(void)
{
    int64_t a, b;
    int32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &ex) {
            std::cout << ex.get_result() << std::endl;
        }
    }
    return 0;
}