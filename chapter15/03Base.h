#ifndef __03BASE_H__
#define __03BASE_H__
#include <iostream>
using namespace std;
class Base
{
  public:
    void pub_mem();

  protected:
    int prot_mem = 0;

  private:
    char priv_mem = 0;
};

struct Pub_Derv : public Base
{
    int f()
    {
        return prot_mem;
    }

    // char g() {return priv_mem;} // 错误：派生类不能访问基类的private成员
};

struct Priv_Derv : private Base
{
    int f() const
    {
        return prot_mem; // private继承不影响派生类的访问权限：私有无法访问，公有和保护变成派生类自己的私有
    }

    // char g() {return priv_mem;} // 错误：派生类不能访问基类的private成员
};

struct Defived_from_Public : public Pub_Derv
{
    int use_base()
    {
        return prot_mem;
    } // 正确：Base的protected成员在Pub_Derv中仍然是protected
};

struct Defived_from_Private : public Priv_Derv
{
    // int use_base() { return prot_mem; } // 错误：Base的protected成员在Priv_Derv中变成了private，无法访问
};

#endif // __03BASE_H__