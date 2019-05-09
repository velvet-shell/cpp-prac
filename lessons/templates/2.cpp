template<typename T, typename F>
T myfilter(const T &v, F f)
{
    T s{};
    for (const auto &x : v)
    {
        if (f(x))
        {
            s.insert(s.end(), x);
        }
    }
    return s;
}