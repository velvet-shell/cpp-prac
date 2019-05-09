#include <cmath>
#include <cstdio>
#include <iostream>

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

    class complex_stack
    {
        enum
        {
            INIT_SIZE = 4,
            MULTIPLIER = 2
        };
        size_t length;
        complex *stack = nullptr;
        size_t top;
    public:
        complex_stack(): length(INIT_SIZE), top(0) {
            stack = new complex[length];
        }
        complex_stack(const complex_stack &a) {
            top = a.top;
            length = a.length;
            stack = new complex[length];
            for (size_t i = 0; i < top; ++i) {
                stack[i] = a.stack[i];
            }
        }
        complex_stack operator=(const complex_stack &a) {
            top = a.top;
            length = a.length;
            delete[] stack;
            stack = new complex[length];
            for (size_t i = 0; i < top; ++i) {
                stack[i] = a.stack[i];
            }
            return *this;
        }
        size_t size() const {
            return top;
        }
        complex& operator [](size_t ind) const {
            return stack[ind];
        }
        complex_stack operator <<(complex z) const {
            complex_stack new_stack = *this;
            if (top == length) {
                new_stack.length *= MULTIPLIER;
                complex *tmp = new complex[new_stack.length];
                for (size_t i = 0; i < top; ++i) {
                    tmp[i] = stack[i];
                }
                delete[] new_stack.stack;
                new_stack.stack = tmp;
            }
            new_stack.stack[top] = z;
            ++new_stack.top;
            return new_stack;
        }
        complex& operator +() const {
            return stack[top - 1]; 
        }
        complex_stack operator ~() const {
            complex_stack new_stack = *this;
            --new_stack.top;
            return new_stack;
        }
        ~complex_stack() {
            delete[] stack;
        }
    };

    complex eval(char **args, const complex &z)
    {
        complex_stack nums;
        int i = 0, top = -1;
        while (args[i])
        {
            char *ptr = args[i++];
            complex tmp1, tmp2;
            switch(*ptr)
            {
                case '+':
                    nums[top - 1] = nums[top - 1] + nums[top];
                    nums = ~nums;
                    top--;
                    break;
                case '-':
                    nums[top - 1] = nums[top - 1] - nums[top];
                    nums = ~nums;
                    top--;
                    break;
                case '*':
                    nums[top - 1] = nums[top - 1] * nums[top];
                    nums = ~nums;
                    top--;
                    break;
                case '/':
                    nums[top - 1] = nums[top - 1] / nums[top];
                    nums = ~nums;
                    top--;
                    break;
                case '!':
                    nums = nums << nums[top];
                    top++;
                    break;
                case ';':
                    nums = ~nums;
                    top--;
                    break;
                case '~':
                    nums[top] = ~nums[top];
                    break;
                case '#':
                    nums[top] = -nums[top];
                    break;
                case 'z':
                    nums = nums << z;
                    top++;
                    break;
                default:
                    nums = nums << complex(ptr);
                    top++;
            }
        }
        return +nums;
    }
}

using namespace numbers;

int main(int argc, char *argv[])
{
    enum { BUF_SIZE = 50 };

    numbers::complex c = complex(argv[1]);
    double r;
    int n;
    sscanf(argv[2], "%lf", &r);
    sscanf(argv[3], "%d", &n);
    complex integral;
    double arg, arg1, arg2;
    for (int i = 0; i < n; ++i) {
        arg = 2 * M_PI / n * (i + 0.5);
        arg1 = 2 * M_PI / n * i;
        arg2 = 2 * M_PI / n * (i + 1);
        integral = integral + eval(argv + 4, c + complex(r * cos(arg) , r * sin(arg))) *
                complex(r * (cos(arg2) - cos(arg1)), r * (sin(arg2) - sin(arg1)));
    }

    char buf[BUF_SIZE];
    integral.to_string(buf, BUF_SIZE);
    puts(buf);
    return 0;
}