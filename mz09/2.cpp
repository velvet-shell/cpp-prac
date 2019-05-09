#include <iostream>

int main(void) {
    enum state { A, B, C, D, E, F, G, H, K, S, ERR};

    char c;
    while ((c = getchar()) != EOF) {
        while (isspace(c)) {
            c = getchar();
            if (c == EOF) {
                return 0;
            }
        }
        state cur = H;
        do {
            switch (cur)
            {
                case H:
                    if (c == '0') {
                        c = getchar();
                        cur = A;
                    } else if (c == '1') {
                        c = getchar();
                        cur = B;
                    } else {
                        cur = ERR;
                    }
                    break;
                case A:
                    if (c == '0') {
                        c = getchar();
                        cur = A;
                    } else if (c == '1') {
                        c = getchar();
                        cur = B;
                    } else {
                        cur = ERR;
                    }
                    break;
                case B:
                    if (c == '0') {
                        c = getchar();
                        cur = C;
                    } else if (c == '1') {
                        c = getchar();
                        cur = D;
                    } else {
                        cur = ERR;
                    }
                    break;
                case C:
                    if (c == '0') {
                        c = getchar();
                        cur = E;
                    } else if (c == '1') {
                        c = getchar();
                        cur = F;
                    } else {
                        cur = ERR;
                    }
                    break;
                case D:
                    if (c == '0') {
                        c = getchar();
                        cur = G;
                    } else if (c == '1') {
                        c = getchar();
                        cur = K;
                    } else {
                        cur = ERR;
                    }
                    break;
                case E:
                    if (c == '0') {
                        c = getchar();
                        cur = A;
                    } else if (c == '1') {
                        c = getchar();
                        cur = B;
                    } else if (isspace(c) || c == EOF) {
                        cur = S;
                    } else {
                        cur = ERR;
                    }
                    break;
                case F:
                    if (c == '0') {
                        c = getchar();
                        cur = C;
                    } else if (c == '1') {
                        c = getchar();
                        cur = D;
                    } else if (isspace(c) || c == EOF) {
                        cur = S;
                    } else {
                        cur = ERR;
                    }
                    break;
                case G:
                    if (c == '0') {
                        c = getchar();
                        cur = E;
                    } else if (c == '1') {
                        c = getchar();
                        cur = F;
                    } else if (isspace(c) || c == EOF) {
                        cur = S;
                    } else {
                        cur = ERR;
                    }
                    break;
                case K:
                    if (c == '0') {
                        c = getchar();
                        cur = G;
                    } else if (c == '1') {
                        c = getchar();
                        cur = K;
                    } else if (isspace(c) || c == EOF) {
                        cur = S;
                    } else {
                        cur = ERR;
                    }
                    break;
                default:
                    break;
            }
        } while (cur != S && cur != ERR);
        if (cur == S) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
            while (!isspace(c) && c != EOF) {
                c = getchar();
            }
        }
    }
    return 0;
}