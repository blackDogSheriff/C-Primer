#include <iostream>
#include <memory>
#include <string>
using namespace std;
int main(void)
{
    return 0;
}
void t_shared_ptr_and_new()
{
    shared_ptr<double> p1;
    shared_ptr<int> p2(new int(42));
    // 不能隐式将内置指针转换程shared_ptr，explicit的
    // shared_ptr<int> p3 = new int(42);  //相同类型才会恢复，没有调用构造函数，直接隐式类型转换
    shared_ptr<int> p4(new int[42]); //直接初始化
}

shared_ptr<int> clone(int p)
{
    // return new int(p); //错误，不能隐式转换
    return shared_ptr<int>(new int(p));
}