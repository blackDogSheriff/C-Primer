#include <iostream>
#include <algorithm>
using namespace std;
/*
- 让类类似一个值
*/

class HasPtr
{
  public:
    HasPtr() = default;
    HasPtr(const string &s = string()) : ps(new string(s)), i(0){};
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i){};
    HasPtr &operator=(const HasPtr &rhs)
    {
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        this->i = rhs.i;
        return *this;
    }
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
    {
        p.ps = 0;
    }
    HasPtr &operator=(const string &rhs)
    {
        swap(*this, rhs);
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

  private:
    string *ps;
    int i;
};