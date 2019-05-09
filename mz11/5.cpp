#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>

int main(void)
{
    std::stack<std::string> st;
    char c;
    while (std::cin >> c) {
        if (islower(c)) {
            st.push(std::string(1, c));
        } else {
            std::string last = st.top();
            st.pop();
            std::string tmp = "(" + st.top() + c + last + ")";
            st.pop();
            st.push(tmp);
        }
    }
    std::cout << st.top() << std::endl;
    st.pop();
    return 0;
}