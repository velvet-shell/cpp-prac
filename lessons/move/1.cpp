#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a{};

    int &ra = a;
    ++ra;

    cout << ra << endl;

    const int &cra = a;
    cout << cra << endl;

    int &&rra = a + 1; //создан безымянный объект, который можно изменять
    ++rra;
    cout << rra << endl;

    const int &cc = a + 1;

    int &&rra2 = move(a);
}