#include <iostream>

using namespace std;

auto f(int s)
{
	cout << s << endl;
	return double(s);
}

auto g(int s) -> auto
{
	cout << s << endl;
	return s;
}

auto h(auto a, auto b) //альтернативная запись шаблона (концепт)
{
	return a + b;
}

int main(int argc, char const *argv[])
{
	auto x = 10;
	cout << f(x) << endl;
	cout << g(20) << endl;
	cout << h(100, 200) << endl;
	return 0;
}