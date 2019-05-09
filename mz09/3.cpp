#include <cstdlib>
#include <string>
#include <iostream>

std::string s;

int cmp(const void *left, const void *right)
{
    return s.substr(*(size_t *) left) > s.substr(*(size_t *) right);
}

int main(void)
{
    getline(std::cin, s);

    size_t end = s.size();
    while (isspace(s[--end]));
    s = s.substr(0, end + 1);

    size_t a[32768];
    for (size_t i = 0; i < s.size(); ++i) {
        a[i] = i;
    }

    std::qsort(a, s.size(), sizeof(*a), cmp);

    for (size_t i = 0; i < s.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}