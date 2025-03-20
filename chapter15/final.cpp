#include <iostream>
using namespace std;

class NoDerived final
{ /* */
};

class Base
{ /* */
};

class Last final Base
{
};
class Bad : NoDerived
{
}; // 错误：final类不可作为基类
class Bad1 : Last
{
}; // 错误：final类不可作为基类

int main(void)
{
    return 0;
}
