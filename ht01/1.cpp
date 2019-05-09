#include <thread>
#include <cstdio>
#include <mutex>
#include <vector>

constexpr int COUNT = 3;
constexpr int ITER = 1000000;

double arr[COUNT];
std::mutex m;

void func(int pos)
{
    m.lock();
    for (int j = 0; j < ITER; ++j) {
        arr[pos % 3] += 100 * (pos + 1);
        arr[(pos + 1) % 3] -= 100 * (pos + 1) + 1;
    }
    m.unlock();
}

int main(void)
{
    for (int i = 0; i < COUNT; ++i) {
        arr[i] = 0;
    }

    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back(func, i);
    }
    for (auto &t : threads) {
        t.join();
    }
    for (int i = 0; i < COUNT; ++i) {
        printf("%.10g\n", arr[i]);
    }
    return 0;
}