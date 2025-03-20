#include <iostream>
using namespace std;

int main(void)
{
    // static_cast
    // 任何明确定义转换，不包含地层const就可以使用static_cast
    // 适合将较大类型转换成较小类型，不在乎精度损失
    double slope = static_cast<double>(j) / i;
    // void指针转换
    void *p = &d;
    double *dp = static_cast<double *>(p);

    // const_cast
    // const_cast只能改变运算对象的地层const(丢掉const属性)，获得写权限
    const char *cp;
    char *q = static_cast<char *>(cp); // 错误，static不能将const转换为非const
    static_cast<string>(cp);           // 字面之转换成string类型
    const_cast<string>(cp);            // 错误，const_cast只能改变常量属性
    const_cast<char *>(cp);            // 应该正确

    // reinterpret_cast
    // 避免使用
    int *ip;
    char *pc = reinterpret_cast<char *>(ip); //*pc中记录的是一个真实的对象，而不是字符
    return 0;
}
