#include <iostream>
#include <memory>

using namespace std;
/*
- weak_ptr: 指向shared_ptr管理的对象，且不增加shared_ptr的引用计数；不影响shared_ptr释放对象
- weak_ptr<T> w
- weak_ptr<T> w(sp)
- w = p
- w.reset()
- w.use_count() //返回shared_ptr的引用计数
- w.expires() // 判断shared_ptr的引用计数是否为0
- w.lock() //如果w.use_count()返回0，则返回空的shared_ptr，否则返回一个指向w对象的shared_ptr；作用是什么？
*/

int main(void)
{
    return 0;
}

void t_create_weak_ptr()
{
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p); //不增加引用计数

    if (shared_ptr<int> sp = wp.lock()) //简单说就是weak_ptr不能操作对象，要操作就必须使用lock返回一个shared_ptr进行操作
    {
        //进行sp操作
    }
}