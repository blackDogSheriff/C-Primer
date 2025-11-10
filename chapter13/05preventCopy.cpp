#include <iostream>
using namespace std;

class NoCopy
{
  public:
    NoCopy() = default;              // 默认构造函数
    NoCopy(const NoCopy &) = delete; // 禁止拷贝构造
    NoCopy &operator=(const NoCopy &) = delete;
    /*
    - 析构函数不能删除
    */
    ~NoCopy() = default;
};

int main(void)
{
    NoCopy a;
    // NoCopy b(a); // 错误：禁止拷贝构造
    // NoCopy c = a; // 错误：禁止拷贝构造
    // b = a; // 错误：禁止拷贝赋值
}