#include <cstdio>
#include <iostream>

//S - 1A0
//A - 1A0 | 0B1
//B - 0B1 | eps

void B(char &c)
{
    if (c == '0') {
        std::cout << 1;
        c = getchar();
        B(c);
        if (c != '1') {
            throw c;
        }
        c = getchar();
        std::cout << 0;
    }
}

void A(char &c)
{
    if (c == '1') {
        c = getchar();
        A(c);
        if (c != '0') {
            throw c;
        }
        c = getchar();
        std::cout << 0;
    } else if (c == '0') {
        std::cout << 1;
        c = getchar();
        B(c);
        if (c != '1') {
            throw c;
        }
        c = getchar();
        std::cout << 0;
    } else {
        throw c;
    }
}

void S(char &c)
{
    if (c == '1') {
        c = getchar();
        A(c);
        if (c != '0') {
            throw c;
        }
        c = getchar();
        std::cout << 0;
    } else {
        throw c;
    }
}

int main(void)
{
    try {
    char c;
    while((c = getchar()) != EOF) {
        while (isspace(c)) {
            c = getchar();
        }
        S(c);
        if (!isspace(c)) {
            throw c;
        }
        std::cout << std::endl;
    }
    } catch (char c) {
        std::cout << "Wrong input " << c << std::endl;
    }
    return 0;
}