#ifndef __06BASE_H__
#define __06BASE_H__

#include <iostream>
using namespace std;
/*
可以使用using修改基类的成员权限
*/

class Base
{
  public:
    size_t size() const
    {
        return n;
    }

  protected:
    size_t n;
};

class Derived : private Base
{
  public:
    using Base::n;
    using Base::size; //权限变成public

  protected:
    using Base::n;
};

int main(void)
{
    Derived D;
    cout << D.n << endl;

    return 0;
}

#endif //__06BASE_H__
