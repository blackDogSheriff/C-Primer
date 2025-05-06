#include <iostream>
using namespace std;
#include <new> // std::nothrow
int main()
{
    return 0;
}
void t_oom()
{
    int *p1 = new int(42);           // 如果分配失败，new 抛出std::bad_alloc异常
    int *p2 = new (nothrow) int(42); // 如果分配失败，new 返回空指针
}