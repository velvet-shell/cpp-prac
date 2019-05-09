#include <iostream>

void skip_chars(int &res, char &c)
{
    res = 0;
    while (!isspace(c) && c != EOF) {
        c = getchar();
    }
}

int main(void)
{
    char c;
    while ((c = getchar()) != EOF) {
        int res = 1;
        int k = 0;
        int m = 0;
        while (isspace(c)) {
            c = getchar();
            if (c == EOF) {
                return 0;
            }
        }
        while (c == '0') {
            k++;
            c = getchar();
        }
        while (c == '1') {
            m++;
            c = getchar();
        }
        if (k == 0 || m == 0) {
            skip_chars(res, c);
        }
        while (!isspace(c) && c != EOF) {
            int tmpk = 0;
            int tmpm = 0;

            while (c == '0') {
                tmpk++;
                c = getchar();
            }
            while (c == '1') {
                tmpm++;
                c = getchar();
            }
            if (tmpk != k || tmpm != m) {
                skip_chars(res, c);
                break;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}