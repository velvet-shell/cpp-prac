#include <algorithm>

template <typename T>
struct Coord
{
    typedef T value_type;
    T row, col;
    Coord(T a = T(), T b = T()): row(a), col(b) {};
};

template <typename T>
T dist(const Coord<T> &grid, const Coord<T> &first, const Coord<T> &second)
{
    T dx = abs(second.row - first.row);
    T dx_off = abs(grid.row - dx);
    dx = std::min(dx , dx_off);

    T dy = abs(second.col - first.col);
    T dy_off = abs(grid.col - dy);
    dy = std::min(dy , dy_off);
    
    return std::max(dx, dy);
}
