#include <iostream>
using namespace std;
/*
- 左值持久，右值短暂
- 右值引用只能绑定临时对象
    - 所引用对象将要被销毁
    - 该对象没有其他用户
*/

struct X
{
    int i;
    string s;
};

/*
如果一个类定义了自己的拷贝构造函数，赋值运算符或者析构函数，编译器就不会为他合成移动构造函数和移动赋值运算符了
*/
struct hasX
{
    X mem;
};

class Foo
{
  public:
    Foo() = default;
    Foo(const Foo &);
};

int main(void)
{
    int i = 42;
    int &r = i;
    int &&rr = i;           //错误，不能将一个右值引用绑定到一个左值上
    int &r2 = i * 42;       //错误，i * 42是一个右值
    const int &r3 = i * 42; // const引用可以绑定到右值
    int &&rr2 = i * 42;     //正确

    // int &&rr3 = rr2; //错误，不能将一个右值引用绑定到一个右值引用类型的变量上
    int &&rr3 = std::move(rr2); //正确

    X x, x2 = move(x); //使用合成的移动构造函数
    hasX hx, hx2 = move(hx);

    Foo x;
    Foo y(x); //拷贝构造函数
    /*
    - move(x)返回一个绑定到x的右值引用，但是没有定义移动构造函数，因此Foo&&转换为一个const Foo &
    */
    Foo z(move(x)); //拷贝构造函数
    return 0;
}