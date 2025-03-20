#include <iostream>
#include <memory>

using namespace std;
int
main(void)
{
    shared_ptr<double> p1;

    shared_ptr<int> p3(make_shared<int>(42));
    // 内置指针转换成智能指针
    shared_ptr<int> p2(new int(42));
    shared_ptr<int> p4 =
        new int(1024); // 错误，构造函数是explict，必须直接初始化

    shared_ptr<int> clone(int p)
    {
        return new int(p); // 错误，隐式转换成了shared_ptr<int>
    }
    shared_ptr<int> clone(int p)
    {
        return shared_ptr<int>(new int(p)); // 显式转换
    }

    // 智能指针和内置指针混合使用会导致内存被释放
    int *x(new int(1024));
    process(x); // 错误：构造函数是explicit的，必须使用直接初始化；
    process(shared_ptr<int>(x)); // 函数调用完毕之后内存会被释放
    int j = x;

    // p.get()返回智能指针的内置指针
    // 永远不要将get()返回值赋值给另一个智能指针
    // get将指针的访问权限传递给代码，只有在确定不会delete指针的情况下才能使用get()
    shared_ptr<int> p(new int(42));
    int            *q = p.get(); // 正确，但是不要释放
    {
        shared_ptr<int>(q); // 程序结束的时候q被销毁，指向的内存被释放
    }
    int foo = *p; // p指向的内存已经被释放了, p被销毁的时候内存会被第二次delete

    // 其他shared_ptr操作
    // reset():释放原有对象，指向新对象
    shared_ptr<int> p;
    p = new int(1024);      // 错误
    p.reset(new int(1024)); // 正确，或者直接初始化

    if (!p.unique())
        p.reset(new string(*p)); // 不是唯一用户，分配新的拷贝
    *p += newVal;                // 唯一用户改变对象值

    // 智能指针与异常
    // 智能指针：无论函数正常结束或者被销毁，内存都会被释放掉
    // 发生异常时，内置指针管理的内存不会自动释放的；
    void f()
    {
        int *ip = new int(42);
        // 抛出异常，且在delete之前发生异常，内存不会释放
        delete ip;
    }

    // 智能指针和哑类
    void end_connection(connection * p)
    {
        disconnect(*p);
    };
    void f(destination & d)
    {
        connection             c = connect(&d);
        shared_ptr<connection> p(&c, end_connection);
        // f退出的时候，connection会被正确关闭
    }

    return 0;
}
