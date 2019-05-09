struct Sum
{
    private:
        int sum = 0;
    public:
        Sum(int a, int b) : sum(a + b) {}
        Sum(const Sum &a, int b) : sum(a.sum + b) {}
        int get() const
        {
            return sum;
        }
};