#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
using namespace std;
/*
- 友元是什么？
    - 类的友元能通过类的对象来访问类的成员
*/

/*
- 基类的友元：
    - 可以通过基类对象访问基类成员
    - 可以通过派生类对象，访问基类成员
- 派生类的友元：
    - 可以通过派生类对象，访问基类和派生类成员
*/

/*
- 友元类的派生类，不会继承被声明成友元
*/

class Base
{
    friend class Pal;

  protected:
    int prot_mem = 0;
};

class Snakey : public Base
{
    friend void clober(Snakey &s);
    friend void clober(Base &b);

    int j;
};

class Pal
{
  public:
    int f(Base b)
    {
        return b.prot_mem;
    }

    int f2(Snakey s)
    {
        /*
        - 错误，基类的友元只能通过基类对象访问基类成员
        - 派生类Snakey并没有继承这个友元

        */
        // return s.j;
    }

    int f3(Snakey s)
    {
        /*
        Pal是Base的友元，可以通过派生类对象，访问基类部分成员
        */
        return s.prot_mem;
    }
};

void clober(Snakey &s)
{
    s.j = s.prot_mem = 10;
}

/*
- 派生类的成员或者友元只能通过派生类的对象来访问基类的protected成员，不能通过基类的对象直接访问；
*/
void clober(Base &b)
{
    // b.prot_mem = 10; // 错误：非派生类不能访问基类的protected成员
}

#endif // __BASE_H__
