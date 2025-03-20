#include <iostream>
#include <memory>

int main(void)
{
	unique_ptr<double> p1;
	unique_ptr<int> p2(new int(42));	//unique_ptr必须采用直接初始化的方式
	//unique_ptr拥有对象，不支持普通的拷贝和赋值
	unique_ptr<string> p1(new string("Stegosaurus"));
	unique_ptr<string> p2(p1);	//错误,不支持拷贝
	unique_ptr<string> p3;
	p3 = p2;	//错误, 不支持赋值

	//release()
	unique_ptr<string> p2(p1.release());	//release将p1置空,返回指针(转移所有权到p2)
	unique_ptr<string> p3(new string("Trex"));	

	p2.reset(p3.release());	//释放p2，获得p3的所有权

	p2.release();	//p2不会释放内存，而且丢失了指针
	auto p = p2.release();	//但是必须delete(p);

	//传递unique_ptr参数和返回unique_ptr
	unique_ptr<int> clone(int p) {
		return unique_ptr<int>(new int(p));	//可以拷贝或者赋值一个即将销毁的unique_ptr
	}
	unique_ptr<int> clone(int p) {
		unique_ptr<int> ret(new int(p));
		return ret;	//返回一个局部对象的拷贝
	}

	//auto_ptr具有unique_ptr部分特性，不可以保存在容器中，也不可以返回
	//虽然auto_ptr是标准库的一部分，但是编写程序的时候应该使用unique_ptr

	//向unique_ptr传递删除器
	void f(destination &d)
	{
		connection c = connect(&d);
		unique_ptr<connection, decltype(end_connection) *>	p(&c, end_connection);
		//使用连接
		//当f退出时，connection会被正确关闭
	}
	return 0;
}
