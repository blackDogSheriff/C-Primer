#include <iostream>
using namespace std;
/*
constexpr类：
- 数据成员都是字面值常量类型的聚合类，是字面值常量类
- 如果一个类不是聚合类，但它符合下述要求，则它也是一个字面值常量类：
    - 数据成员都必须是字面值类型
    - 类必须含有一个constexpr构造函数
    - 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式 ||
如果成员属于某种类型，则初始值必须使用成员自己的constexpr构造函数
    - 类必须使用析构函数的默认定义，该成员负责销毁类的对象
*/
class Debug
{
  public:
    //至少有一个构造函数为constexpr的
    // constexpr构造函数必须初始化所有的数据成员，初始值、constexpr构造函数或者常量表达式
    constexpr Debug(bool b = true) : hw(b), io(b), other(b){};
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){};

    constexpr bool any() const
    {
        return hw || io || other;
    }

    void set_io(bool b)
    {
        io = b;
    };

    void set_hw(bool b)
    {
        hw = b;
    }

    void set_other(bool b)
    {
        other = b;
    }

  private:
    //成员都是字面值类型
    bool hw;
    bool io;
    bool other;
};

int main(void)
{
    constexpr Debug io_sub(false, true, false);

    if (io_sub.any())
        cerr << "print appropriate error message" << endl;
}
