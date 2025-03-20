#include <iostream>
using namespace std;

// 如果基类中的成员是private的，则派生类无权访问
// 如果静态成员可访问，则可以通过派生类或者基类访问
class Base {
public:
    static void statmem();
};
class Derived : public Base {
    void f(const Derived &);
};
void
Derived::f(const Derived &derived_obj)
{
    Base::statmem();       // 基类访问
    Derived::statmem();    // 派生类访问
    derived_obj.statmem(); // 通过Derived对象访问
    statmem();             // 通过this访问
}
int
main(void)
{
    return 0;
}
