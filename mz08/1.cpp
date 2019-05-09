#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s) {
        auto search = s.find_first_not_of("34");
        if (search == string::npos ||
                (search != string::npos && s.find_first_not_of("12", search) == string::npos)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}