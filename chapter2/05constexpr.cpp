#include <iostream>
using namespace std;

constexpr int square(int x);
int main(void)
{
    /* 常量表达式：值不会改变，并且在编译过程就能得到计算结果的表达式；
    - 字面值
    - 已初始化的const对象
    */
    const int max_files = 20;
    const int limit = max_files + 1;

    /* C++11规定，允许将变量声明为constexpr类型以便由编译器来验证变量的值
    是否是一个常量表达式；
    */
    constexpr int mf = 20;         // 常量表达式
    constexpr int limit1 = mf + 1; // 常量表达式
    // constexpr int sz = size(); //
    // 只有当size是一个constexpr函数的时候才是正确语句

    /*
    常量表达式编译的时候就要计算，因此，声明constexpr时用到的类型必须有所限制
    ，这些类型必须为字面值类型：算数类型、引用、指针等；
    */

    constexpr int result = square(5);
    return 0;
}
constexpr int square(int x)
{
    return x * x;
}