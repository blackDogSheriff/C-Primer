#include <iostream>
using namespace std;
int main(void)
{
    /*
    顶层const：指针本身是一个常量；
    顶层const：变量本身的值不能改变；
    底层const：解引用后的地址指向的buf的值不能改变
    */

    int i = 0;
    int *const pi = &i; // 顶层const

    const int ci = 42; // 顶层const
    /*
    底层const：指针所指的对象是一个常量；
     */
    const int *p2 = &ci; // 底层const

    const int *const p3 = p2; // 底层const
    const int &r = ci;        // 底层const

    // int *p = p3; // 错误：底层const不能赋值给没有底层const的；
    p2 = p3;
    p2 = &i;

    // int &r1 = ci; // 错误：ci为底层const，不可以去掉；
    const int &r2 = i; // 正确：可以将非底层const变量赋值给底层const的引用；
}