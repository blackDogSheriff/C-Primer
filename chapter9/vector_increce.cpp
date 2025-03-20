#include <iostream>
#include <vector>
using namespace std;
/*
	c.size();			//返回元素个数
	c.capacity();		//最大可以容纳的元素个数
	c.shrink_to_fit();	//只适用于vector,string,deque
	c.reserve(n);		//至少分配n个元素容纳空间
	c.resize();			//设置大小
*/
void print(const vector<int> &iv)
{
	cout << "ivec: size: " << iv.size() 
		 << " capacity: : " << iv.capacity() << endl;
}

int main(void)
{
	vector<int> ivec;
	print(ivec);

	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	print(ivec);

	ivec.reserve(50);
	print(ivec);

	while(ivec.size() != ivec.capacity())
		ivec.push_back(0);
	print(ivec);

	ivec.push_back(0);
	print(ivec);

	ivec.shrink_to_fit();
	print(ivec);

	ivec.resize(20);
	print(ivec);
	return 0;
}
