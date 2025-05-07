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
}