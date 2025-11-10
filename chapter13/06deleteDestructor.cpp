#include <iostream>
using namespace std;
/*
- 析构函数删除、无法访问，则不会合成默认析构函数
- 拷贝构造函数是删除或者不可访问，则不会和成默认析构函数
    - 如果类的析构函数被定义为删除的，则不会合成默认拷贝构造函数（因为无法释放）
- 类成员不可拷贝赋值（const或者没有拷贝构造函数），那么该类的合成拷贝赋值运算符也定义为删除；
*/

struct NoDtor
{
    NoDtor() = default; // 默认构造函数
    ~NoDtor() = delete; // 禁止析构函数
};
int main(void)
{
    NoDtor a;                 //析构函数被删除，无法创建
    NoDtor *p = new NoDtor(); //正确，但是不能delete p
    delete p;                 //因为p的析构函数被删除，因此不能delete
    return 0;
}