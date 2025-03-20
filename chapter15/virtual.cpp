#include <iostream>
using namespace std;
struct B
{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};
struct D1 : B
{
    void f1(int) const override; // 正确
    void f2(int) override;       // 错误：参数列表不匹配
    void f3() override;          // 错误：f3不是虚函数
    void f4() override;          // 错误：没有该函数
};

// 被定义为final的函数不可以进行覆盖
// 哪怕是继承的虚函数
struct D2 : B
{
    void f1(int) const final;
};
struct D3 : D2
{
    void f2();          // 省略了override
    void f1(int) const; // 错误：D2已经将f2的声明变成了final,f2默认虚函数，省略了override
};
int main(void)
{
    // 回避虚函数的机制
    // 强行调用基类中的net_price函数，而不管baseP实际指向的对象到底是什么类型
    // 该调用在编译的时候就已经完成解析
    double undiscounted = baseP->Quote::net_price(42);
    return 0;
}
/*
笔记：
    1.
虚函数默认是参，使用调用指针的静态类型，和动态类型无关；一般基类和派生类默认实参一致；

*/
