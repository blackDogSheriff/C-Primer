#include <iostream>
using namespace std;

int main(void)
{
    /*
     * - 引用必须初始化
     */
    int ival = 1024;
    int &refVal = ival;
    // int &refVal2; // error: reference must be init
    cout << ival << endl;

    // 赋值
    refVal = 2;
    cout << ival << endl;

    // 取值
    int ii = refVal;
    cout << ii << endl;

    // 使用引用作为绑定对象，实际绑定到引用绑定的对象；
    int &refVal3 = refVal;
    refVal3 = 3;
    cout << ival << endl;

    // reference destination
    int i = 1024, i2 = 2048;
    int &r = i, r2 = i2; // r是引用，r2是int；

    // int &refVal4 = 10; // 错误，引用类型初始值必须为一个对象；
    double dval = 3.14;
    // int   &refVal5 = dval; // 错误，类型不匹配；

    // 引用不是对象，因此指针不能指向引用，但是引用可以指向指针；
    int *p1 = nullptr;
    int *&r1 = p1;
}