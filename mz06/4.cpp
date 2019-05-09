#include <cmath>

namespace Game
{
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
        T dx = std::abs(first.col - second.col);
        T dy = first.row - second.row;
        T off = dx / 2;

        if ((dy < 0 && !(first.col % 2)) || (dy > 0 && first.col % 2)) {
            off += dx % 2;
        }

        dy = std::abs(dy);

        if (off >= dy) {
            return dx;
        } else {
            return dx + dy - off;
        }
    }
}