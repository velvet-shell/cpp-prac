#include <thread>
#include <iostream>
#include <sstream>
#include <vector>

void func(int a, double b, const std::string &str, int &val)
{
    std::ostringstream oss;
    oss << a << "\n" << b << "\n" << str << "\n" << (void *) &str << "\n";
    std::cout << oss.str();
    val = 100;
}


//пример с несколькими нитями
int main(void)
{
    std::vector<std::thread> vt;


    //на количество нитей есть некоторый лимит
    //$ ulimit -a
    //неявное ограничение: для каждой нити создается стек
    //(память аллоцируется при вызове конструктора нити и больше не изменяется (не расширяется), остается до конца жизни нити)
    for (int i = 0; i < 20; ++i) {
        std::thread thr([](int val) { std::cout << val; }, i);
        //у класса thread нет конструктора копирования - нельзя использовать push_back
        //нужна move семантика
        vt.push_back(std::move(thr));

        //другие способы
        //vt.push_back(std::thread([](int val) { std::cout << val; }, i));
        //vt.emplace_back([](int val) { std::cout << val; }, i);
    }

    for (auto &t : vt) {
        t.join();
    }
}