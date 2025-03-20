#include <iostream>
using namespace std;
int main(void)
{
    constexpr int foo = new_sz();
    // 允许constexpr函数的返回值并非一个常量
    // 当cnt是常量表达式的时候，返回值是常量表达式
    return 0;
}

constexpr int new_sz()
{
    return 42;
}

constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}

/*
笔记：
    1. constexpr函数指的是能用于常量表达式的函数.
    2. 函数返回类型及所有形参都是字面值类型
    3. 函数体中只有一条热return语句
    4. constexpr函数被隐式的指定为内联函数
    5. 内联函数和constexpr函数可以在程序中要多次定义，
        但是多个定义必须完全一致（通常定义在头文件中）
*/
