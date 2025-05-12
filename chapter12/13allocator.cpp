#include <iostream>
#include <memory>

/*
- allocator<T> a;
- a.allocate(n); //分配n个未初始化的T对象
- a.dealllocate(p, n); //释放p指向的n个T对象
- a.construct(p, args);
- a.destory(p);
*/

using namespace std;

void t_allocator();
void t_print(const string *p, size_t n);
int main(void)
{
    t_allocator();
    return 0;
}

void t_allocator()
{
    /*
    - 分配并且初始化n个string
    - 存在问题：
        - 分配对象数量固定的，可能用不到
        - 用到的对象初始化了两次
    */
    string *const p1 = new string[5];

    /*
    - 使用allocator分配对象：隔离分配和构造
     */
    allocator<string> alloc;
    auto const p = alloc.allocate(5); //奉陪5个未初始化的string对象
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, '9');
    alloc.construct(q++, "hi");

    t_print(p, 5);
    t_print(q, 5); //错误：经过偏移，q已经移动到了没有构造的内存

    while (q != p)
    {
        alloc.destroy(--q); //释放构造的string
    }
    alloc.deallocate(p, 5); //释放内存（也就是没有构造的string）
}

void t_print(const string *p, size_t n)
{
    for (size_t i = 0; i != n; ++i)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}