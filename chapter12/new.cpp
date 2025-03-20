#include <iostream>
using namespace std;
int
main(void)
{
    // 分配一个无名内存，返回指向该对象的指针
    int *pi = new int; // 默认情况下，值默认初始化，也就是为定义的
    int *pi = new int(); // 值初始化为空
    int *pi = new int(1024);

    string     *ps = new string;  // 默认初始化为空string
    string     *ps = new string() // 值初始化为空string
        string *ps = new string(10, '9');

    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 使用auto
    auto p1 = new auto(obj); // p1为int*

    // 分配const对象
    const int *pci = new const int(1024); // 分配并默认初始化一个const int
    // 动态分配的const对象也必须初始化，但是有默认构造函数可以隐式初始化
    const string *pcs = new const string; // 分配并默认初始化一个空的string

    // 内存耗尽-抛出bad_alloc异常
    int *p1 = new int;           // 分配失败抛出bad_alloc
    int *p2 = new (nothrow) int; // 分配失败返回空指针

    // 释放动态内存
    delete p; // p必须指向一个动态分配的对象或者是一个空指针
    int     i, *pil = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    delete i;   // 错误：i不是一个指针
    delete pil; // 为定义： pil指向一个局部变量
    delete pd;  // 正确
    delete pd2; // 为定义, 指向的内存已经被释放过
    delete pi2; // 释放一个空指针总是没有错的

    // 函数返回指向分配的动态存储区的指针需要手动释放
    // 局部指针指向分配的存储区，在函数结束的时候会造成内存泄漏

    // 重置指针
    int *p(new int(42));
    auto q = p;
    delete p;
    p = nullptr; // 但是没有重置q
    return 0;
}
