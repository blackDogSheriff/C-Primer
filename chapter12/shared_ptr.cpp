#include <iostream>
#include <memory>
using namespace std;
int main(void)
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	if (p1 && p1->empty())
		*p1 = "hi";
	
	//make_shared-使用类型构造函数初始化-返回shared_ptr指针
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();

	//shared_ptr拷贝和赋值
	//无论何时拷贝shared_ptr，计数器都会计数
	//计数为0的时候，就会自动销毁所管理的对象
	auto p = make_shared<int>(42);
	auto q(p);	//pq指向相同对象，此时对象有两个引用者

	//shared_ptr还会自动释放相关联的内存
	//p是局部变量，p在use_factory运行结束的时候会被销毁，如果计数值不为0，则同时销毁其指向的内存
	//但是如果有其他的shared_ptr指向该内存，就不会销毁
	shared_ptr<Foo> factory(T arg)
	{
		return make_shared<Foo>(arg);
	}
	void use_factory(T arg)
	{
		shared_ptr<Foo> p = factory(arg);
	}
	return 0;
}
