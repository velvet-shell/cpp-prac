#include <iostream>

using namespace std;

template<typename C>
void myswap(C &a, C &b)
{
	auto tmp{a};
	a = b;
	b = tmp;
}

template<typename C>
void myswap(C *a, C *b)
{
	auto tmp{*a};
	*a = *b;
	*b = tmp;
}

template<> //специализация шаблона
void myswap(int &a, int &b)
{
	cout << "int" << endl;
}


int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	myswap<int>(a, b);
	cout << a << " " << b << endl;

	double c = 1.1, d = 2.2;
	myswap(c, d);
	cout << c << " " << d << endl;

	double *pc = &c, *pd = &d;
	cout << (void *) pc << " " << (void *) pd << endl;
	//myswap(pc, pd);
	myswap<double *>(pc, pd);
	cout << (void *) pc << " " << (void *) pd << endl;
	cout << c << " " << d << endl;
	return 0;
}