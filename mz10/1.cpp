#include <iostream>
#include <string>

int verify(std::string s)
{
    bool st = true;
    for (size_t i = 0; i < s.size(); ++i) {
        if (st && (s[i] == '2' || s[i] == '1')) {
            st = false;
        }
        if (!st && (s[i] == '3' || s[i] == '4')) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int k;
    std::cin >> k;
    std::string str, fin;
    for (int i = 0; i < k; i++) {
        str += '1';
        fin += '4';
    }

    while (str != fin) {
        if (!verify(str)) {
            std::cout << str << std::endl;
        }
        for (int i = k - 1; i >= 0; --i) {
            if (str[i] == '4') {
                str[i] = '1';
            } else {
                ++str[i];
                break;
            }
        }
    }
    if (k > 0) {
        std::cout << fin << std::endl;
    }
    return 0;
}