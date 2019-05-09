#include <iostream>

void g(int &r)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void g(int &&r)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void g(int const &r)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename C>
void func(C &&value) //universal reference
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    g(std::forward<C>(value)); //perfect forwarding
}

int main()
{
    int a = 0;
    const int b = 0;
    int &c = a;
    const int &d = b;
    int e = 2;
    int &&f = std::move(e);

    func(a);
    func(b);
    func(c);
    func(d);
    func(e);
    func(std::move(f));
    func(100);
    return 0;
}