#include <iostream>
using namespace std;
int main(void)
{
    // 函数类形由返回值类型和参数类型共同决定
    bool lengthCompare(const string &, const string &);
    bool (*pf)(const string &, const string &);
    // 赋值：两者相同
    pf = lengthCompare;
    pf = &lengthCompare;
    // 调用
    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");

    // 重载函数指针
    void ff(int *);

    void ff(unsigned int);

    // 指针类型必须与重载函数中的某一个精确匹配
    void (*pf1)(unsigned int) = ff;
    void (*pf2)(int) = ff;
    double (*pf3)(int *) = ff;

    // 函数指针做行参
    void useBigger(const string &s1, const string &s2,
                   bool pf(const string &, const string &)); // 第三个参数为函数类型，自动转换成函数指针

    void useBigger(const string &s1, const string &s2,
                   bool (*pf)(const string &, const string &)); // 显式的将形参定义成指向函数的指针

    useBigger(s1, s2, lengthCompare);

    // 函数类型别名
    typedef bool Func(const string &, const string &); // 起别名Func
    typedef decltype(lengthCompare) Func2;             // 起别名Func2

    // 函数指针别名
    typedef bool (*FuncP)(const string &, const string &);
    typedef decltype(lengthCompare) *FuncP2;

    void useBigger(const string &, const string &, Func);
    void useBigger(const string &, const string &, FuncP2);

    // 返回函数指针
    using F = int(int *, int);
    typedef int F(int *, int); // 等价

    using PF = int (*)(int *, int);
    typedef int (*pf)(int *, int); // 函数指针别名

    // 不可以返回函数类型
    PF f1(int);
    F f1(int); // 错误
    F *f1(int)

        // 直接声明返回函数指针的函数
        int (*f1(int))(int *,
                       int); // f1是函数，返回类型为int (*)(int *, int);	由内向外看

    // 使用auto和decltype用于函数指针类型
    string::size_type sumLength(const string &, const string &);
    string::size_type largerLength(const string &, const string &);
    // decltype返回函数类型而不是指针
    decltype(sumLength) *getFcn(const string &); // 返回函数指针
    string::size_type (*getFcn(const string &))(const string &, const string &);

    return 0;
}
