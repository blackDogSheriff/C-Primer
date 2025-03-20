#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
	int a = 10;
	int *p = new int;
	shared_ptr<int> ptr(p);
}
