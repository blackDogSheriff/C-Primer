#include <iostream>

using namespace std;

class Base
{
  public:
    virtual int fcn();
};

class D1 : public Base
{
  public:
    int fcn(int);      // 新定义函数，且不是虚函数
    virtual void f2(); // 一个新的虚函数，在base中不存在
};

class D2 : public D1
{
  public:
    int fcn(int); // 新定定义的函数，隐藏了D1中的函数
    int fcn();    // 覆盖了Base中的虚函数fcn
    void f2();    // 覆盖了D1中的虚函数f2
};

int main(void)
{
    return 0;
}
