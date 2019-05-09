#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	vector <string> vs;
	string s;

	while (cin >> s) {
		vs.push_back(move(s));
	}

	for (const auto &z : vs) {
		cout << z << endl;
	}
	return 0;
}