#include <iostream>
using namespace std;
// 字面值常量类
/*
    1. 数据成员都是字面之类型的聚合类，是字面值常量类
    2. 数据成员都是字面值类型；至少含有一个constexpr构造函数；
        如果数据成员含有类内初始值，则初始值是常量表达式；
        如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数；
        类必须使用析构函数的默认定义；
    3. constexpr构造函数体一般是空的；
*/
class Debug
{
  public:
    // constexpr构造函数必须初始化所有成员
    constexpr Debug(bool b = true) : hw(b), io(b), other(b){};
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){};
    constexpr bool any()
    {
        return hw || io || other;
    }

    void set_io(bool b)
    {
        io = b;
    }
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_other(bool b)
    {
        hw = b;
    }

  private:
    bool hw;
    bool io;
    bool other;
};
int main(void)
{
    constexpr Debug io_sub(false, true, true);

#if 0
    if (io_sub.any())
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false);
    if (prod.any())
        cerr << "print an error message" << endl;
#endif
}
