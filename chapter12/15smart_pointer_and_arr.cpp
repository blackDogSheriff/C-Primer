#include <iostream>
#include <memory>

using namespace std;

void t_unique_ptr();
int main(void)
{
    t_unique_ptr(); // 测试 unique_ptr
    return 0;
}

void t_unique_ptr()
{
    int *x = new int[4]{1, 2, 3, 4};
    unique_ptr<int[]> p1(x);
    p1.release();                              // 释放p1的所有权，x仍然有效
    cout << "p1.get() = " << p1.get() << endl; // p1.get()返回nullptr

    for (int i = 0; i < 4; ++i)
        cout << x[i] << " "; // x仍然有效，输出1 2 3 4
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