#include <iostream>
using namespace std;

int main(void)
{
    // const: 修饰变量中的值不能改变
    //  const must be init
    const int i = 42;

    int i1 = 42;
    const int ci = i;
    int i2 = ci;

    // 对常量的引用
    const int &r1 = ci;

    // const initialization
    int i3 = 42;
    const int &r2 = i3;
    const int &r3 = 42;     // 正确，常量引用绑定常量；
    const int &r4 = r2 * 2; // 正确，常量引用绑定常量；
    // int &r5 = r2 * 2; //错误，非常亮引用不能绑定常量

    double d = 1.23;
    const int &rd = d; // rd绑定了一个临时变量，该变量进行了强转
    cout << rd << endl;
}