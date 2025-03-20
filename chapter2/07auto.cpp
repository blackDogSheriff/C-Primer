#include <iostream>
#include <typeinfo>

using namespace std;

int main(void)
{
    // auto通过初始值推断类型，auto必须有初始值
    auto i = 0, *p = &i;
    // auto sz = 0, pi = 3.14; // 错误：两者类型不一致

    /*
    auto和引用：
    */

    int i1 = 0, &r = i1;
    auto a = r; // a 是引用绑定的对象的类型

    /*
    auto一般回忽略顶层const,但是底层const会保留
    */
    const int ci = i, &cr = ci; // ci是常量，cr是指向常量ci的引用；
    auto b = ci;                // int：ci的顶层const被忽略
    auto c = cr;                // int：cr是底层const，c是const int，顶层const舍弃
    auto d = &i;                // int *
    auto e = &ci;               // const int *：对常量去地址结果为底层const

    /*
    符号&和*只属于某个声明，并非基本的数据类型，因此初始值类型一致也就是
    说需要去掉变量前面的&或者*；
     */
    auto k = ci, &l = i;
    auto &m = ci, *p1 = &ci; // const int&, const int *
    // auto &n = i, *p2 = ci; /// 错误：前者类型为int，后者为const int

    return 0;
}