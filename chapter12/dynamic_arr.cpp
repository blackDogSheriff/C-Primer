#include <iostream>
using namespace std;
int main(void)
{
    // 可以使用非常量设定动态数组的元素个数，因为动态数组不是数组；
    int *pia = new int[getsize()];

    // 使用别名创建动态数组
    typedef int arrT[42];
    int *p = new arrT;

    // 动态数组的初始化
    int *pia = new int[10];         // 默认初始化
    int *pia = new int[10]();       // 值初始化为0
    string *psa = new string[10];   // 调用string构造函数初始化为空?
    string *psa = new string[10](); // 值初始化为空?

    //()可以进行值初始化，但是不能在括号中给出初始化器
    int *pia3 = new int[10]{0, 1, 2, 3, 5, 6, 7, 8, 9}; // 使用初始化器初始化
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
    // bad_array_new_length	bad_alloc异常

    // 动态数组的处理
    size_t n = get_size();
    int *p = new int[n];
    for (int *q = p; q != p + n; ++q)
        /* 处理数组 */
        /* 如果getsize()返回0，new返回一个合法的非空指针，但是不指向任意元素
           因此不能对返回的指针解引用 */
        // 释放动态数组
        delete p;
    delete[] pa; // 数组中的元素逆序销毁

    // 智能指针和动态数组
    unique_ptr<int[]> up(new int[10]);
    up.release(); // 释放所有权，调用delete销毁指针(release本身不会释放内存)
    /* shared_ptr必须提供一个删除器 */
    shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
    sp.reset();
    for (size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i;

    return 0;
}
/*
笔记
    1. 使用new分配动态数组，并不是真的创建了数组
    2. 不可以对动态数组使用begin和end函数
    3. 不可以对动态数组使用范围for
*/
