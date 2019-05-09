//тип языка 0

#include <iostream>
#include <string>

int main(void) {
    std::string s;
    while (std::cin >> s) {
        int m = 0, n = 0;
        int type = 1;
        size_t i = 0;
        size_t sz = s.size();

        while (i < sz && s[i] == 'a') {
            m++;
            i++;
        }
        if (i == sz || m == 0) {
            type = 0;
        }
        while (i < sz && s[i] == '0') {
            n++;
            i++;
        }
        if (i == sz || n == 0) {
            type = 0;
        }

        int check = 0;
        while (i < sz && s[i] == 'b') {
            check++;
            i++;
        }
        if (i == sz || check != m) {
            type = 0;
        }
        check = 0;
        while (i < sz && s[i] == '1') {
            check++;
            i++;
        }
        if (i != sz || check != n) {
            type = 0;
        }
        std::cout << type << std::endl;
    }
    return 0;
}