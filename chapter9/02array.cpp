#include <iostream>
#include <array>

using namespace std;
int main(void)
{
    array<string, 10> b;
    array<int, 10>::size_type i;
    // array<int>::size_type j; //错误，array<int>不是一个类型

    //初始化列表中的值必须和array的大小相同
    array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return 0;
}