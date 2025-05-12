#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
}

void t_unique_ptr()
{
    unique_ptr<int[]> p1(new int[10]);
    p1.release(); //析构函数调用delete[]销毁内存
    for (size_t i = 0; i != 10; ++i)
    {
        p1[i] = i;
    }
}

void t_shared_ptr()
{
    shared_ptr<int> p1(new int[10], [](int *p) { delete[] p; });
    for (size_t i = 0; i != 10; ++i)
    {
        p1.get()[i] = i; //先通过get()获取内置指针，然后使用
    }
    p1.reset(); //使用lambda表达式进行释放
}