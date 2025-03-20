#include <iostream>
using namespace std;
class Base {
public:
    size_t size() const
    {
        return n;
    }

protected:
    size_t n;

private:
    size n1; // 派生类无法访问，不能提供using声明
};

class Derived : private Base {
public:
    using Base::size; // 修改访问控制权限为public
protected:
    using Base::n; // 修改访问控制权限为protected,可以被派生类访问
};

int
main(void)
{
    return 0;
}
