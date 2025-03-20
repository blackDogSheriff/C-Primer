#include <iostream>
#include <map>

using namespace std;

int add(int i, int j)
{
    return i + j;
}
int main(void)
{
    map<string, function<int(int, int)>> binops = {
        {"+", add},                                // 函数指针,不可以直接使用函数名(二义性)
        {"-", minus<int>()},                       // 标准库函数对象
        {"/", divide()},                           // 用户定义的函数对象
        {"*", [](int i, int j) { return i * j; }}, // 未命名的lanbda
        {"%", mod}                                 // 命名了的mod
    };

    binops["+"](10, 5);
    return 0;
}
