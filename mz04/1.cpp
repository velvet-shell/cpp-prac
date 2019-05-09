template<typename T>
typename T::value_type process(const T &v)
{
    typename T::value_type s = typename T::value_type();
    typename T::const_reverse_iterator i = v.rbegin();

    if (i == v.rend()) {
        return s;
    }
    s += *i;
    
    for (int k = 0; k < 2; ++k) {
        ++i;
        if (i == v.rend()) {
            break;
        }
        ++i;
        if (i == v.rend()) {
            break;
        }
        s += *i;
    }
    return s;
}