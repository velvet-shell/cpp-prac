#include <iostream>

template <typename C0, typename ...C1>
struct MyTuple
{
    C0 arg0;
    MyTuple<C1...> argz;

    MyTuple(C0 &&c0, C1 &&...c1) : arg0(c0), argz(std::forward<C1>(c1)...) {}
};

template <typename C>
struct MyTuple<C>
{
    C arg0;

    MyTuple(C &&arg0) : arg0(arg0) {}
};

template <typename C1, typename C2>
struct MyTuple<C1, C2>
{
    C1 arg1;
    C2 arg2;
};

int main()
{
    
    return 0;
}