#include <iostream>
using namespace std;
struct First
{
    int memi;
    int getMem();
};

struct Second
{
    int memi;
    int getMem();
};

//----------------------------------------------------------------
typedef double Money;
string bal;
class Account
{
    //可以
    // typedef double Money;

  public:
    Money balance()
    {
        return bal;
    }
    //不可以，类型名称已经使用过
    // typedef double Money;

  private:
    Money bal;
};

int main(int argc, char *argv[])
{
    return 0;
}