#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, function<int (int, int) >> binOps = {
	{ "+", plus<int>()},
	{ "-", minus<int>()},
	{ "*", multiplies<int>()},
	{ "/", divides<int>()},
	{ "%", modulus<int>()}
}
int main(void)
{
	return 0;
}
