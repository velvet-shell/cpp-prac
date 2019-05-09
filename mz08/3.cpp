#include <iostream>
#include <string>
#include <ctype.h>

int main(void)
{
    std::string a, b;
    bool type1 = true, type2 = true;
    bool has_s = false, rules = false;
    bool right_s = false, has_empty = false;
    
    while (std::cin >> a >> b) {
        rules = true;
        bool current_s = false;
        if (a.size() == 1 && a[0] == 'S') {
            has_s = true;
            current_s = true;
        } else {
            bool check = false;
            for (char &c : a) {
                if (isupper(c)) {
                    check = true;
                }
                if (!isupper(c) && !islower(c) && !isdigit(c)) {
                    std::cout << -1 << std::endl;
                    return 0;
                }
            }
            if (!check) {
                std::cout << -1 << std::endl;
                return 0;
            }
            if (a.size() > 1) {
                type2 = false;
            }
        }

        if (b.size() == 1 && b[0] == '_') {
            has_empty = true;
            if (!current_s) {
                type1 = false;
            }
        } else {
            for (char &c : b) {
                if (c == 'S') {
                    right_s = true;
                }
                if (!isupper(c) && !islower(c) && !isdigit(c)) {
                    std::cout << -1 << std::endl;
                    return 0;
                }
            }
        }
    }

    if (!rules || !has_s) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (has_empty && right_s) {
        type1 = false;
    }

    if (type1 && type2) {
        std::cout << 23 << std::endl;
    } else if (type2) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 10 << std::endl;
    }
    return 0;
}