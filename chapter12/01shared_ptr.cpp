#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;
int main()
{
    return 0;
}

void t_shared_ptr_init()
{
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;

    if (p1 && p1->empty()) // p1是一个对象，因此可以先判断p1是否存在，再判断p1是否为空
    {
        *p1 = "hi";
    }

    shared_ptr<int> p3 = make_shared<int>(42); // 动态分配一个int，并初始化为42
    // 使用类型的构造函数初始化
    shared_ptr<string> p4 = make_shared<string>(10, '9'); // 动态分配一个string，并初始化为10个'9'
    shared_ptr<int> p5 = make_shared<int>();              // 动态分配一个int，并初始化为0，默认初始化
    //使用auto自动推断类型
    auto p6 = make_shared<vector<string>>();
    auto p7(p6); //创建一个和p6一样的shared_ptr并指向p6指向的动态内存，p6指向计数器也+1

    /*
    * - 当指向一个对象的最后一个shared_ptr被销毁时，shared_ptr会通过析构函数来销毁被指向的对象；
    * - shared_ptr销毁时，析构函数会递减引用计数，如果引用计数为0，则释放内存；
    */
    auto p8 = make_shared<int>(42);
    auto p9 = p8; // 给p9赋值；递增p8的引用计数；递减p9原来的引用计数；如果p9原来的yin引计数为0，则释放内存
}
