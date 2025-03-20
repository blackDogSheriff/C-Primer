#include <iostream>
using namespace std;
class Base
{
};
class Pal
{
  public:
    int f(Base b)
    {
        return b.prot_mem;
    }

  private:
};
int main(void)
{

    return 0;
}
