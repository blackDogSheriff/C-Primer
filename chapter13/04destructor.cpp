#include <iostream>
#include <memory>
#include <vector>
#include "01Sales_data.cpp"

using namespace std;
/*
- 析构函数
    - 释放对象使用资源，销毁非静态数据成员
    - 不能被重载
    - 先执行函数体，然后销毁成员，成员按照初始化逆序被销毁
    - 析构部分是隐式的，不放在函数体中
    - 被销毁成员执行自己的析构函数
    - 销毁内置指针类型的成员不会delete其指向的对象
    - 智能指针在析构阶段会释放内存

    - 有析构就有拷贝：因为析构函数意味着类中存在某种资源，如动态内存释放，文件句柄等
        - 因此，默认拷贝构造函数无法拷贝这种资源，需要自定义拷贝
*/

int main(void)
{
}

void t_destructor()
{
    Sales_data *p = new Sales_data;      //内置指针，需要手动释放
    auto p2 = make_shared<Sales_data>(); //共享指针
    Sales_data item(*p);                 //拷贝构造
    vector<Sales_data> vec;              //局部对象
    vec.push_back(*p2);
    delete p; //手动释放内置指针
}
/*
- 离开局部作用域
    - itrem，p2，vec调用析构函数
    - 销毁p2递减引用计数，计数为0则对象释放
    - 销毁vector，会自动销毁其元素
 */