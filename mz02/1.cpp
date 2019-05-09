#include <cmath>
#include <cstdio>

namespace numbers
{
    class complex
    {
        double re, im;
    public:
        complex (double a_re = 0, double a_im = 0): re(a_re), im(a_im) {}
        explicit complex (const char *a) {
            sscanf(a, "(%lf,%lf)", &re, &im);
        }
        double get_re () const {
            return re;
        }
        double get_im () const {
            return im;
        }
        double abs2 () const {
            return re * re + im * im;
        }
        double abs () const {
            return sqrt(re * re + im * im);
        }
        void to_string (char *buf, size_t size) const {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }
        friend complex operator ~(const complex &a);
        friend complex operator -(const complex &a);
        friend complex operator +(const complex &a, const complex &b);
        friend complex operator -(const complex &a, const complex &b);
        friend complex operator *(const complex &a, const complex &b);
        friend complex operator /(const complex &a, const complex &b);
    };

    complex operator ~(const complex &a) {
        return complex(a.re, -a.im); 
    }
    complex operator -(const complex &a) {
        return complex(-a.re, -a.im);
    }
    complex operator +(const complex &a, const complex &b) {
        return complex(a.re + b.re, a.im + b.im);
    }
    complex operator -(const complex &a, const complex &b) {
        return complex(a.re - b.re, a.im - b.im);
    }
    complex operator *(const complex &a, const complex &b) {
        return complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
    }
    complex operator /(const complex &a, const complex &b) {
        return complex((a.re * b.re + a.im * b.im) /
                b.abs2(), (b.re * a.im - a.re * b.im) / b.abs2());
    }
}