#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

int main(void)
{
    std::multimap<std::string, std::pair<char, std::string>> automata;
    char ch;
    std::string cur, nw;
    std::cin >> cur;
    while (cur.compare("END") != 0) {
        std::cin >> ch >> nw;
        automata.insert({cur, {ch, nw}});
        std::cin >> cur;
    }

    std::set<std::string> exit;
    std::cin >> cur;
    while (cur.compare("END") != 0) {
        exit.insert(cur);
        std::cin >> cur;
    }
    std::string current_state;
    std::cin >> current_state;

    int i = 0;
    bool check = 1;
    while (std::cin >> ch) {
        auto states = automata.equal_range(current_state);
        bool found = 0;
        for (auto it = states.first; it != states.second; ++it) {
            if ((it->second).first == ch) {
                current_state = (it->second).second;
                found = 1;
            }
        }
        if (!found) {
            check = 0;
            break;
        }
        ++i;
    }
    if (check && !exit.count(current_state)) {
        check = 0;
    }
    
    std::cout << check << std::endl;
    std::cout << i << std::endl;
    std::cout << current_state << std::endl;

    return 0;
}