#include <iostream>

//S aSd | aQd 
//Q bQc | bc

void generate(int k, int b)
{
    if (b == -1) {
        ++b;
        for (; k > 1; --k, ++b) {
            generate(k - 1, b + 1);
            std::cout << std::endl;
        }
        return;
    }
    if (k > 0) {
        std::cout << "a";
        generate(k - 1, b);
        std::cout << "d";
    } else {
        std::cout << "b";
        if (b > 1) {
            generate(0, b - 1);
        }
        std::cout << "c";
    }
}

int main(void)
{
    int k;
    std::cin >> k;
    if (k % 2 == 0) {
        generate(k / 2, -1);
    }
    return 0;
}