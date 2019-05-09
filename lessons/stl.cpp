//vector
//list
//forward_list - односвязный
//deque
//
//array - фиксирован при компиляции
//string
//
//[multi]set(двоичное дерево поиска)
//[multi]map
//unordered_set
//         _map

//RandomAccessIter
//BidirectionalIter

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class MyVector {
    int buf[10];
    int size;
public:
    MyVector(std::initializer_list<int> val) {
        int i = 0;
        for (auto elem : val) {
            buf[i] = elem;
            ++i;
        }
        size = val.size();
    }
    int *begin() {
        return buf;
    }
    int *end() {
        return buf + size;
    }
};

class MyVector2 {
    std::string *buf;
    int size;
    int capacity;
public:
    MyVector() {
    }

    void push_back(const std::string& s) {
            if (size >= capacity) { //внутри очень плохой код
                capacity *= 2 + 1;
                //std::string *tmp = new std::string[capacity]; //плохо, т.к. вызывает конструкторы -> может нарушить логику
                std::string *tmp = malloc(sizeof(std::string) * capacity);
                for (int i = 0; i < size; ++i) {
                    new (tmp + i) std::string(buf[i]); //вызываем конструктор над выделенным куском памяти
                    //tmp[i] = buf[i];
                }
                //delete[] buf;
                for (int i = 0; i < size; ++i) {
                    buf[i]::~string();
                }
                free(buf);
                buf = tmp;
            }
            new (buf + size) string(s);
    }
    int *begin() {
        return buf;
    }
    int *end() {
        return buf + size;
    }
};

int main() {
    std::vector<int> v = {1, 4, 5};

    for (auto elem : v) {
        std::cout << elem;
    }

    v.push_back(4); //O(1), в середину - O(N); все предыдущие итераторы инвалидируются

    MyVector v1{3, 1, 2};

    for (auto elem : v1) {
        std::cout << elem;
    }

    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.reserve(1000);
    std::cout << v.capacity() << std::endl;
    v.resize(1);
    std::cout << v.capacity() << std::endl;
    v.shrink_to_fit();
    std::cout << v.capacity() << std::endl;

    // std::sort(v.begin(), v.end()); //rbegin, rend

    // for (std::vector<int>::const_iterator it = v.cbegin(); it < v.cend(); ++it) {
    //     std::cout << *it << std::endl;
    // }
    struct T {
        int a, b;
    };

    MyVector2 v2;
    v2.push_back(T{1, 2});
    v2.emplace_back(1, 2); //не создается временный объект
    return 0;
}