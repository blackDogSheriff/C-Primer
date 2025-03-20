#include <iostream>
using namespace std;
int main(void)
{
	plus<int> intAdd;
	negate<int> intNegate;

	int sum = intAdd(10, 20);
	sum = intNegate(intAdd(10, 20));
	sum = intAdd(10, intNegate(10));
	cout << sum << endl;
	return 0;
}
