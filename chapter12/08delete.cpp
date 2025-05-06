#include <iostream>
using namespace std;
int main()
{
    return 0;
}

void t_delete()
{
    int *p1 = new int(42);
    delete p1;    // 释放动态分配的内存
    p1 = nullptr; // 重置指针

    /*
    - 只能delete动态分配的内存
    - 局部变量不能被delete
    - 相同内存释放多次是未定义的
    */
    int i, *p1 = &i, *p2 = nullptr;
    double *p3 = new double(33), *p4 = p3;
    // delete i;  // 错误：i不是一个指针
    // delete p1; // 未定义： p1指向一个局部变量
    delete p3;
    delete p4; // 未定义：指向的内存已经被释放过
    delete p2; // 释放一个空指针总是没有错的

    const int *p5 = new const int(42);
    delete p5; // 底层const可以delete
}

template <typename T> string *factory(T arg)
{
    return new string(arg);
}

void use_factory()
{
    string *p1 = factory("hello");
    // delete p1; // 释放动态分配的内存
} // p1离开了作用域，但是指向的内存没有释放