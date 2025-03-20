#include <iostream>
using namespace std;

class X
{
  public:
    //错误，实际上是i先初始化，然后使用未定义的j对i进行初始化；
    X(int val) : j(val), i(j){};

    X &print()
    {
        cout << i << " " << j << endl;
        return *this;
    }

  private:
    int i;
    int j;
};

int main(void)
{
    X x(3);
    x.print();
    return 0;
}