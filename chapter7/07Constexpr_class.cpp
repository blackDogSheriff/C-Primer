#include <iostream>
using namespace std;
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
    }

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
