#include <iostream>
using namespace std;
struct absInt
{
	int operator()(int val) const
	{
		return val < 0 ? -val : val;
	}
};
int main(void)
{
	return 0;
}
