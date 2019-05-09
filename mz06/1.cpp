#include <iostream>
#include <string>

struct StringKeeper
{
    std::string str;
    ~StringKeeper() {
        if (!str.empty()) {
            std::cout << str << std::endl;
        }
    }
};

void read_strings(void) {
    StringKeeper obj;
    if (std::cin >> obj.str) {
        read_strings();
    } else {
        throw 1;
    }
}

int main(void)
{
    try {
        read_strings();
    } catch(...) {
    }
    return 0;
}