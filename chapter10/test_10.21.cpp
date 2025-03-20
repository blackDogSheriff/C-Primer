#include <iostream>
#include <algorithm>

using namespace std;

void mutable_lambda(void)
{
	int val = 42;
	//mutable 可以修改val
	auto f() = [val] () mutable -> bool{ if (i > 0) { i--; return false; } esle
			return true; };
	for (int j = 0; j < val; j++)
		cout << f() << " ";
	cout << endl;
	return 0;
}

int main(int argc, char *argv[])
{
	mutable_lambda();
	return 0;
}
