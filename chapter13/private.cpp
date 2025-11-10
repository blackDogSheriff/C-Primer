#include <iostream>
using namespace std;
class PrivateCopy
{
    // class 默认private
    PrivateCopy(const PrivateCopy &);
    PrivateCopy &operator=(const PrivateCopy &);

  public:
    PrivateCopy() = default;
    ~PrivateCopy(); //可以定义该类型对象，但是不能析构（delete或者无法访问？）
};
int main(void)
{
    return 0;
}

/*
笔记：
    1. 析构函数public用户可以定义PrivateCopy类型的对象
    2. 拷贝构造函数和拷贝赋值运算符式private的，用户代码不能拷贝对象
    3. 将拷贝控制成员声明成private的，但是不定义他们，可以阻止友元和成员函数拷贝对象
    4. 析构函数没有函数体，则不能销毁函数
*/
