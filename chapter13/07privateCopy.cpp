#include <iostream>
using namespace std;
/*
- 阻止拷贝合法操作应该是使用 = delete；，而不是声明为private
- 析构函数是public的：用户可以创建该对象
- 拷贝构造是private的：用户不可以拷贝对象
- 但是友元和成员函数可以进行拷贝，声明为private但是不定义，来阻止友元和成员函数惊醒拷贝
*/

class PrivateCopy
{
  public:
    PrivateCopy() = default;
    ~PrivateCopy();

  private:
    PrivateCopy(const PrivateCopy &) = default;
    PrivateCopy &operator=(const PrivateCopy &);
}

int main(void)
{
}