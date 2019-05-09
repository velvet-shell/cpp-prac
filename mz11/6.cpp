#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(void)
{
    std::map<std::string, int> labels;
    std::vector<std::string> sequence;

    std::string s;
    int k = 1;
    
    while (std::cin >> s) {
        if (s.back() == ':') {
            s.pop_back();
            labels.insert(std::pair<std::string, int>(s, k));
        } else {
            sequence.push_back(s);
            ++k;
        }
    }

    for (auto &tmp : sequence) {
        if (labels.count(tmp) > 0) {
            tmp = std::to_string(labels[tmp]);
        }
    }

    for (auto tmp: sequence) {
        std::cout << tmp << std::endl;
    }
    return 0;
}