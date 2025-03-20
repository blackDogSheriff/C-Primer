#include <iostream>
#include <memory>
using namespace std;
int main(void)
{
	auto p = make_shared<int>(42);
	weak_ptr<int> wp(p);	//不改变shared_ptr计数

	if (shared_ptr<int> np = wp.lock()) {
		//在if中，np与p共享对象
	}
	return 0;
}
