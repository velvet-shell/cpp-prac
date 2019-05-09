#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

std::pair<int, int> check(
        const std::multimap<std::string, std::pair<char, std::string>> &automata,
        const std::set<std::string> &exit,
        const std::string &input,
        std::string current_state,
        size_t pos)
{
    if (pos == input.size()) {
        return {exit.count(current_state), pos};      
    }
    auto states = automata.equal_range(current_state);
    bool found = 0;
    int max = pos;
    for (auto it = states.first; it != states.second; ++it) {
        if ((it->second).first == input[pos] || (it->second).first == ' ') {
            found = 1;
            std::pair<int, int> res;
            if ((it->second).first == ' ') {
                res = check(automata, exit, input, (it->second).second, pos);
            } else {
                res = check(automata, exit, input, (it->second).second, pos + 1);
            }
            if (res.first) {
                return res;
            } else if (res.second > max) {
                max = res.second;
            }
        }
    }
    if (!found) {
        return {0, pos};
    } else {
        return {0, max};
    }

}

int main(void)
{
    std::multimap<std::string, std::pair<char, std::string>> automata;
    std::string cur, ch, nw;
    std::cin >> cur;
    while (cur.compare("END") != 0) {
        std::cin >> ch >> nw;
        if (ch.compare("eps") == 0) {
            automata.insert({cur, {' ', nw}});
        } else {
            automata.insert({cur, {ch[0], nw}});
        }
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

    std::string input;
    std::cin >> input;

    auto res = check(automata, exit, input, current_state, 0);
   
    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;

    return 0;
}