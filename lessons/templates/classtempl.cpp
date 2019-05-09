#include <iostream>

//traits

template<typename T>
struct is_int
{
	static constexpr auto value = false;
};

template<>
struct is_int<int>
{
	static constexpr auto value = true;
};

using namespace std;

int main(int argc, char const *argv[])
{
	cout << is_int<double>::value << endl;
	cout << is_int<int>::value << endl;

	int x;
	static_assert(is_int<decltype(x)>::value); //не скомпилируется, если не int;
	return 0;
}