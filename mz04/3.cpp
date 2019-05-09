#include <functional>
#include <vector>

template<typename T, typename F>
void myapply(T beg, T end, F f)
{   
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

template<typename T, typename F>
std::vector<std::reference_wrapper<typename T::value_type>> myfilter2(T beg, T end, F f)
{   
    std::vector<std::reference_wrapper<typename T::value_type>> v{};
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            v.insert(v.end(), std::reference_wrapper<typename T::value_type>(*beg));
        }
    }
    return v;
}

template<typename T, typename F>
void myapply(T *beg, T *end, F f)
{   
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

template<typename T, typename F>
std::vector<std::reference_wrapper<T>> myfilter2(T *beg, T *end, F f)
{   
    std::vector<std::reference_wrapper<T>> v{};
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            v.insert(v.end(), std::reference_wrapper<T>(*beg));
        }
    }
    return v;
}