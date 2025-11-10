#include <iostream>
using namespace std;

//派生类也能重定义在其直接或间接基类中的名字
//此时定义在内层作用域的名字将隐藏在外层作用域的名字；
struct Base
{
    Base() : mem(0){};

  protected:
    int mem;
};

struct Derived : Base
{ //默认public继承
    Derived(int i) : mem(i){};
    int get_mem()
    {
        return mem;
    }
    //可以使用作用域运算符显式调用外层成员（隐藏派生类成员）
    int get_mem_base()
    {
        return Base::mem;
    }

  protected:
    int mem;
};

int main(void)
{
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_mem_base() << endl;
    return 0;
}
