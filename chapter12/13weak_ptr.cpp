#include <iostream>
#include <memory>
using namespace std;
/*
- weak_ptr<T> w
- weak_ptr<T> w(p) //w指向共享指针 p所指向的对象，p必须是shared_ptr，指向类型为T

- w = p //p可以是shared_ptr或weak_ptr，w指向p所指向的对象
- w.reset() //w指向nullptr
- w.use_count() //返回w所指向的对象的引用计数(shared_ptr)
- w.expired() //如果w所指向的对象已经被释放，返回true
- w.lock() //如果expired()返回true，则返回空，否则返回一个shared_ptr
*/

void weak_ptr_init();
int main()
{
    weak_ptr_init(); // 初始化weak_ptr
    return 0;
}

void weak_ptr_init()
{
    auto p = make_shared<int>(42); // 创建一个shared_ptr
    weak_ptr<int> w(p);
    auto p1 = w.lock();                             // w.lock()会增加引用计数
    cout << "Use count: " << w.use_count() << endl; // 输出引用计数
}