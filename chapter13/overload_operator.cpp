#include <iostream>
using namespace std;

class Foo
{
public:
	Foo &operator= _(const Foo &); // 一般返回左侧运算对象的引用
};
int main(void)
{
	// 等价于合成拷贝赋值运算符
	Sales_data &Sales_data::operator=(const Sales_data &rhs)
	{
		bookNo = rhs.bookNo;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
	}
	return 0;
}

/*
笔记：
	1. 拷贝运算符：是一个重载的赋值运算符，定义为类的成员函数，左侧运算对象绑定到this指针，右侧参数传递
	2. 使用=调用拷贝构造运算符
	3. 合成拷贝运算符会将右侧对象的非static成员逐个赋予左侧对象对应的成员；
	4. 没有定义拷贝构造函数，编译器会默认定义；即便存在其他构造函数，编译器也会为我们合成；
	5. 拷贝构造函数的第一个参数必须是一个引用
*/
