#include <iostream>
#include <memory>

using namespace std;
int main(void)
{
    return 0;
}

void f()
{
    shared_ptr<int> p1(new int(42));
    //抛出异常，指针指向的p1被释放
}

void f1()
{
    int *x = new int(42);
    //此处抛出异常，如果异常没有被捕获，则不会释放
    delete x; // x被释放
}
