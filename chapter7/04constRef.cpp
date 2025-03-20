#include <iostream>
using namespace std;

class ConstRef
{
  public:
    ConstRef(int ii);

  private:
    int i;
    const int ci;
    int &ri;
};

#if 0
ConstRef::ConstRef(int ii)
{
    i = ii;
    ci = i; //错误，没有进行初始化，而是赋值，导致错误
    ri = i;
}
#endif

//正确，执行初始化而不是赋值
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(ii){};

int main(void)
{
    return 0;
}