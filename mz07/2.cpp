#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int i = 1;
    char state = 'S';
    while (1) {
        switch (state) {
            case 'S':
                if (s[i] == '0') {
                    ++i;
                } else if (s[i] == '1') {
                    state = 'A';
                    ++i;
                } else {
                    cout << s;
                    return 0;
                }
                break;
            case 'A':
                if (s[i] == '0') {
                    ++i;
                } else if (s[i] == '1') {
                    ++i;
                    state = 'S';
                } else {
                    state = 'B';
                    --i;
                }
                break;
            case 'B':
                if (s[i] == '0') {
                    --i;
                } else if (s[i] == '1') {
                    --i;
                } else {
                    state = 'C';
                    ++i;
                }
                break;
            case 'C':
                if (s[i] == '0') {
                    ++i;
                } else if (s[i] == '1') {
                    s[i] = '0';
                    cout << s;
                    return 0;
                } else {
                    cout << s;
                    return 0;
                }
                break;
            case 'D':
                cout << s;
                return 0;
                break;
        }
    }
    return 0;
}