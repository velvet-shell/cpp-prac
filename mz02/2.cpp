namespace numbers
{
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
}