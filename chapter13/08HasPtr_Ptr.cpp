#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
  public:
    HasPtr() = default;
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)){};
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use)
    {
        ++*use;
    }

    HasPtr &operator=(const HasPtr &rhs)
    {
        /*
        首先释放本对象的原指向动态内存
         */
        ++*rhs.use;
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }

        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

  private:
    string *ps;
    int i;
    size_t *use;
};