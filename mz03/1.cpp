#include <iostream>
#include <vector>

void process(const std::vector<int> &v1, std::vector<int> &v2, int step)
{
    auto it2 = v2.begin();
    for (auto it1 = v1.begin(); it1 < v1.end(); ++it2) {
        if (it2 == v2.end()) {
            break;
        }
        *it2 = *it1;
        
        auto overflow = it1;
        it1 += step; 
        if (it1 < overflow) {
            break;
        }
    }
    for (auto it = v2.rbegin(); it < v2.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}