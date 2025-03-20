#include <iostream>
using namespace std;

typedef string::size_type sz;

sz wd = 20;
char def = 'd';

int main(void)
{
    // 默认实参右侧必须全部都是实参
    string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
    // 使用实参
    string window = screen();
    window = screen(66);
    window = screen(66, 65);
    window = screen(44, 22, '&'); // 只能省略尾部实参
    //    window = screen(, , '*');     // 错误

    // 实参可以在声明的时候给值
    string screen(sz, sz, char = ' ');

    // 但是不能修改已有的默认值
    // string screen(sz, sz, char = '*');

    // 可以添加默认实参
    string screen(sz = 23, sz = 32, char = '*');

    // 局部变量不能作默认实参
    sz ht();
    string screen(sz = ht(), sz = wd, char = def); // wd, def 必须为全局变量

    // 之后在函数调用的时候才从变量取值，因此可以该函数调用前改变其值

    return 0;
}
