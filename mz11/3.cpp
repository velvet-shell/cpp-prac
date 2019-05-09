#include <iostream>
#include <map>
#include <set>
#include <ctype.h>

int main()
{
    std::multimap<char, std::string> grammar;
    std::set<char> nonterms;
    char c;
    while (std::cin >> c) {
        std::string str = std::string();
        if (getchar() != '\n') {
            std::cin >> str;
        }
        grammar.insert({c, str});
        nonterms.insert(c);
    }
    std::set<char> nullable;
    size_t last_size = 0;
    bool is_changed = 1;
    while (is_changed) {
        last_size = nullable.size();
        for (const auto &tmp : grammar) {
            if (tmp.second.empty()) {
                nullable.insert(tmp.first);
            } else {
                bool is_nonterm = 1, is_nullable = 1;
                for (const auto &ch : tmp.second) {
                    if (!isupper(ch)) {
                        is_nonterm = 0;
                    }
                    if (!nullable.count(ch)) {
                        is_nullable = 0;
                    }
                }
                if (is_nonterm && is_nullable) {
                    nullable.insert(tmp.first);
                }
            }
        }
        if (last_size == nullable.size()) {
            is_changed = 0;
        }
    }
    for (const auto &tmp : nonterms) {
        std::cout << tmp << " " << nullable.count(tmp) << std::endl;
    }
    std::map<char, std::set<char>> first;
    for (const auto &ch : nonterms) {
        first.insert({ch, std::set<char>()});
    }
    is_changed = 1;
    while (is_changed) {
        is_changed = 0;
        for (const auto &tmp : grammar) {
            last_size = first[tmp.first].size();
            if (!tmp.second.empty()) {
                if (!isupper(tmp.second[0])) {
                    first[tmp.first].insert(tmp.second[0]);
                } else {
                    for (const auto &ch : first[tmp.second[0]]) {
                        first[tmp.first].insert(ch);
                    }
                    size_t i = 1;
                    while (i < tmp.second.size() && nullable.count(tmp.second[i - 1])) {
                        if (isupper(tmp.second[i])) {
                            for (const auto &ch : first[tmp.second[i]]) {
                                first[tmp.first].insert(ch);
                            }
                        } else {
                            first[tmp.first].insert(tmp.second[i]);
                        }
                        ++i;
                    }
                }
            }
            if (first[tmp.first].size() != last_size) {
                is_changed = 1;
            }
        }
    }
    for (const auto &tmp : nonterms) {
        std::cout << tmp << " ";
        for (const auto &ch : first[tmp]) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    std::map<char, std::set<char>> follow;
    for (const auto &ch : nonterms) {
        follow.insert({ch, std::set<char>()});
    }
    is_changed = 1;
    while (is_changed) {
        is_changed = 0;
        for (const auto &tmp : grammar) {
            for (size_t i = 0; i < tmp.second.size(); ++i) {
                last_size = follow[tmp.second[i]].size();
                if (isupper(tmp.second[i])) {
                    size_t j = i + 1;
                    while (j < tmp.second.size() && (j == i + 1 || nullable.count(tmp.second[j - 1]))) {
                        if (isupper(tmp.second[j])) {
                            for (const auto &ch : first[tmp.second[j]]) {
                                follow[tmp.second[i]].insert(ch);
                            }
                        } else {
                            follow[tmp.second[i]].insert(tmp.second[j]);
                        }
                        ++j;
                    }
                    if (j == i + 1 || nullable.count(tmp.second[j - 1])) {
                        for (const auto &ch : follow[tmp.first]) {
                            follow[tmp.second[i]].insert(ch);
                        }
                    }
                }
                if (follow[tmp.second[i]].size() != last_size) {
                    is_changed = 1;
                }
            }
        }
    }
    for (const auto &tmp : nonterms) {
        std::cout << tmp << " ";
        for (const auto &ch : follow[tmp]) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}