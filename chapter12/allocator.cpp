#include <iostream>
#include <memory>
using namespace std;
int main(void)
{
	//分配的n个元素可能有用不到的
	string *const p = new string[n];
	string s;
	string *q = p;
	while (cin >> s && q != p + n)
		*q++ = s;
	const size_t size = q - p;
	delete [] p;


	/* 
		a.allocate(n);		//分配n个对象
		a.deallocate(p, n);	//p式allocate返回的指针，n是allocate创建时的大小，
							//调用deallocate之前需要调用destory()
		a.construct(p, args);
		a.destory(p);		//对p指向的对象执行析构函数
	*/

	allocator<string> alloc;	//创建可以分配string的allocator对象
	auto const p = alloc.allocate(n);	//分配n个未初始化的string
	auto q = p;	//遍历每一个n指向的未构造的函数
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");

	while (q != p)
		alloc.destory(--q);	//释放构造的每一个string，只能对真正构造了的元素进行destory操作	
	alloc.deallocate(p, n);

	auto p = alloc.allocate(vi.size() * 2);
	auto q = uninitalized_copy(vi.begin(), vi.end(), p);
	uninitalized_fill_n(q, vi.size(), 42);
	



	return 0;
}
