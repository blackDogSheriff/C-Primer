#include <iostream>
#include <memory>
using namespace std;

// 前置声明模板函数
template <typename T> shared_ptr<int> factory(T arg);
void t_use_shared_ptr();

int main(void)
{
    t_use_shared_ptr();
    //此时p1已经释放了，同时p1的引用计数也减1，结果为0，指向的动态内存被释放
    return 0;
}

void t_use_shared_ptr()
{
    shared_ptr<int> p1 = factory(1);
}

// 完整模板实现
template <typename T> shared_ptr<int> factory(T arg)
{
    return make_shared<int>(arg);
}