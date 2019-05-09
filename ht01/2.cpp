#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <utility>


void operate(
    std::vector<double> &accounts,
    std::vector<std::mutex> &locks,
    uint32_t iter,
    uint32_t index1,
    uint32_t index2,
    double val1,
    double val2)
{
    if (index1 > index2) {
        std::swap(index1, index2);
        std::swap(val1, val2);
    }
    for (uint32_t i = 0; i < iter; ++i) {
            locks[index1].lock();
            locks[index2].lock();

            accounts[index1] += val1;
            accounts[index2] += val2;

            locks[index1].unlock();
            locks[index2].unlock();
    }
}

int main(void)
{
    uint32_t acc_count, thr_count;
    std::cin >> acc_count >> thr_count;

    std::vector<double> accounts(acc_count);
    std::vector<std::mutex> locks(acc_count);
    std::vector<std::thread> threads;

    for (uint32_t i = 0; i < thr_count; ++i) {
        uint32_t iter, index1, index2;
        double val1, val2;
        std::cin >> iter >> index1 >> val1 >> index2 >> val2;
        threads.emplace_back(operate, std::ref(accounts), std::ref(locks), iter, index1, index2, val1, val2);
    }

    for (auto &tmp : threads) {
        tmp.join();
    }

    for (auto &tmp : accounts) {
        printf("%.10g\n", tmp);
    }
    return 0;
}