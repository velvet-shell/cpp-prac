#include <complex>
#include <array>
#include <vector>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> v)
    {
        std::pair<bool, std::vector<std::complex<T>>> tmp;
        if (v[0] == (T)0.0 && v[1] == (T)0.0 && v[2] == (T)0.0) {
            tmp.first = false;
            return tmp;
        }
        tmp.first = true;
        if (v[1] == (T)0.0 && v[2] == (T)0.0) {
            return tmp;
        }
        if (v[2] == (T)0.0) {
            tmp.second.push_back(-v[0] / v[1]);
            return tmp;
        }
        std::complex<T> d = std::sqrt(v[1] * v[1] - (T)4.0 * v[0] * v[2]);
        tmp.second.push_back((-v[1] - d) / ((T)2.0 * v[2]));
        tmp.second.push_back((-v[1] + d) / ((T)2.0 * v[2]));
        return tmp;
    }
}