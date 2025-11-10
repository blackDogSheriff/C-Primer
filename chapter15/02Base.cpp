#include <iostream>
using namespace std;

class Base
{
  public:
    static void statmem();
};

class Derived final : public Base
{
    void f(const Derived &);
};

void Derived::f(const Derived &d)
{
    d.statmem(); // 派生类可以访问基类的静态成员
}

int main(void)
{

    Base::statmem();
    Derived::statmem();

    return 0;
}