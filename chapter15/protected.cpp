#include <iostream>
using namespace std;
/*
    派生类的成员和友元只能访问派生类对象中的基类部分的受保护成员，
    对于普通基类对象中的成员不具有特殊的访问权限
*/

class Base
{
    friend class Pal;

  public:
    void pub_mem();

  protected:
    int prot_mem;

  private:
    char priv_mem;
};
class Sneaky : public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    int f()
    {
        return prot_mem;
    } // 派生类也可以直接访问基类的protected部分
    //	char g() { return priv_mem; }	//错误：派生类不可以访问private成员
    int j;
};
/*
    派生访问说明符不影响派生类的访问权限
    对基类的访问权限只与基类中的
*/
class Priv_Derv : private Base
{
    int f1() const
    {
        return prot_mem;
    } // private继承不影响访问权限
};

struct Derived_from_Public : public Sneaky
{
    int use_base()
    {
        return prot_mem;
    }
};

#if 0
struct Derived_from_Private : public Priv_Derv {
	int use_base() { return prot_mem; }	//继承了个寂寞
};
#endif

class Pal
{
  public:
    int f(Base b)
    {
        return b.prot_mem;
    }
    // int f2(Sneaky s) { return s.j; }
    // //Pal不是Sneaky的友元，无法访问派生类中定义的成员
    int f3(Sneaky s)
    {
        return s.prot_mem;
    } // 派生类继承的基类的成员也可以被基类友元访问
};

void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0; // 通过Sneaky派生类对象访问Base的protected成员
                          // 友元函数可以访问私有成员
}
/*
void clobber(Base &s)
{
    s.prot_mem = 0;			//只能通过派生类对象访问
}
*/							//派生类的友元只能访问派生类定义的成员，不可以访问继承自基类的成员
int main(void)
{
    Sneaky d1;    // 继承自Base的成员是public的
    Priv_Derv d2; // 继承自Base的成员是private的

    // d1.pub_mem();	//正确，d1的成员是public的
    // d2.pub_mem();
    // //错误，d2的成员是private的，不能直接访问，智能通过成员访问
    return 0;
}
