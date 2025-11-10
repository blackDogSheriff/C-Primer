#include <iostream>
#include "01Sales_data.cpp"
using namespace std;

/*
- 拷贝赋值运算符
    - 函数名：operator=
    - 参数：一个常量引用类型
    - 返回值：返回指向左侧对象引用类型
*/

Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this; //返回左侧对象引用
}
