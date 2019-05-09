#include <memory>
#include <iostream>
#include <vector>

using namespace std;
using std::unique_ptr;

struct A {
	int a;
	~A() { cout << "~A"; }
};

// void f(A *pa) {
// 	delete pa;
//}

void f(unique_ptr<A> pa, unique_ptr<A> ppa) {
	cout << pa->a;
}

int main()
{
	unique_ptr<A> pa = unique_ptr<A>(new A{});
    vector<unique_ptr<A>> va;
    va.push_back(unique_ptr<A>(new A{}));
	//f(pa.release());
	//f(pa.get());
	//f(move(pa));
    // f(unique_ptr<A>(new A{}), unique_ptr<A>(new A{})); //возможна утечка памяти
    // unique_ptr<A> pa1(new A{});
    // unqiue_ptr<A> pa2(new A{});
    // f(move(pa1), move(pa2)); //правильно
    f(make_unique<A>(), make_unique<A>());
	return 0;
}