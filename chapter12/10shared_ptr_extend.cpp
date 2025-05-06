#include <iostream>
#include <memory>
using namespace std;
int main()
{
    return 0;
}
/*
- shared_ptr<T> p(new) //p 管理new指向的对象，必须能转换为T *类型
- shared_ptr<T> p(u) //p 接管unique_ptr u的所有权，将u置空
- shared_ptr<T> p(new, d) //p 管理new指向的对象，必须能转换为T *类型，使用自定义的 deleter d
- shared_ptr<T> p(p2, d) //拷贝shared_ptr p2，使用自定义的 deleter d
- p.reset() //重置p，释放p指向的对象，p指向nullptr
- p.reset(q) //重置p，释放p指向的对象，p指向q
- p.reset(q, d) //重置p，释放p指向的对象，p指向q，使用自定义的 deleter d)
*/
template <typename T> void t_delete(T *p);
void t_shared_ptr_extend()
{
    shared_ptr<int> p1(new int(42));
    int *p2 = new int(32);
    shared_ptr<int> p3(p2, t_delete<int>); // p2和p1共享同一块内存
    // shared_ptr<int> p4(p1, t_delete<int>); // p1和p2共享同一块内存
}

template <typename T> void t_delete(T *p)
{
    delete p;
}
