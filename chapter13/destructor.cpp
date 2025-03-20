#include <iostream>
#include <memory>
using namespace std;

class Sales_data {
public:
	~Sales_data() { }	//空析构函数执行完毕之后，成员自行销毁
};
int main(void)
{
	
	//无论何时销毁一个对象，都会自动调用其析构函数
	Sales_data *p = new Sales_data;
	auto p2 = make_shared<Sales_data>();
	Sales_data itrm(*p);
	vector<Sales_data> vec;
	vec.push_back(*p2);


	delete p;

	return 0;
} //退出局部作用域, 对item、p2和vec调用的析构函数
  //销毁p2会递减其引用计数；如果引用计数变为0，对象被释放；
  //销毁vec会销毁他的元素
/* 
笔记：
	析构函数：
		1. 析构函数释放对象使用的资源，并且销毁对象的非static数据成员；
		2. 析构函数不能重载；
		3. 析构函数唯一；
		4. 构造函数：先按照定义顺序初始化成员，然后执行函数体；
		   析构函数：先执行函数体，然后逆须销毁成员；
		5. 在对象最后一次使用之后，析构函数的函数体可以执行类设计者希望执行的任何收尾工作
		   通常，析构函数释放对象在生存期分配的所有资源
		6. 内置类型没有析构函数，销毁内置类型成员什么也不需要做；
		   智能指针是一个类，具有析构函数，智能指针成员在析构的时候，会销毁指向的对象；

*/
