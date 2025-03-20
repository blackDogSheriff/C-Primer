#include <iostream>
using namespace std;
class IfElseThen {
public:
    IfElseThen() {}
    IfElseThen(int i1, int i2, int i3)
        : ival1(i1)
        , iVal2(i2)
        , iVal3(i3)
    {
    }
    int operator()(int il, int i2, int i3)
    {
        return il ? i2 : i3;
    }

private:
    int iVal1, iVal2, iVal3;
};
int
main(void)
{
    return 0;
}
