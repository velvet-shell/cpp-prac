#include <iostream>
#include <string>
#include <map>
#include <set>
#include <ctype.h>

int main(void) {
    std::multimap<char, std::string> grammar;
    char c;
    std::string str;
    while (std::cin >> c >> str) {
        grammar.insert({c, str});
    }
    std::set<char> reachable;
    reachable.insert('S');

    bool is_changed = 1;
    size_t last_size;
    while (is_changed) {
        is_changed = 0;
        last_size = reachable.size();
        for (const auto &tmp : grammar) {
            if (reachable.count(tmp.first)) {
                for (const auto &ch : tmp.second) {
                    if (isupper(ch)) {
                        reachable.insert(ch);
                    }
                }
            }
        }
        if (reachable.size() != last_size) {
            is_changed = 1;
        }
    }
    for (const auto &tmp : grammar) {
        if (reachable.count(tmp.first)) {
            std::cout << tmp.first << " " << tmp.second << std::endl;
        }
    }
    return 0;
}