#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

constexpr int COUNT = 5;
constexpr int ITER = 100000;

volatile long long value1 = 0;
volatile long long value2 = 0;

std::mutex m;

class wrapper
{
    std::mutex &m;
public:
    wrapper(std::mutex &m) : m(m) { m.lock(); }
    ~wrapper() { m.unlock(); }
};

int main(void)
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([](int diff) {
            //цикл на самом деле не выполнится, потому что слишком простой,
            //так что race condition по факту не будет.
            //сделаем переменные volatile, чтобы вычисления не выполнялись на регистрах
            for (int i = 0; i < ITER; ++i) {
                //std::unique_lock<std::mutex> w{m};
                std::unique_lock w{m};
                //wrapper w{m};
                //m.lock();
                value1 += diff;
                value2 -= diff;
                //m.unlock();
            }
        }, (i + 1) * 100);
    }
    for (auto &t : threads)
        t.join();

    std::cout << value1 << "\n" << value2 << "\n";
    return 0;
}