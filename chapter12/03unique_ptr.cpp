#include <iostream>
#include <memory>

using namespace std;
/*
- unique_ptr<T> u
- unique_ptr<T, D> u //可以指向T类型对象。如果传递了D则会使用可调用的D来释放，如果没有D则使用delete释放
- unique_ptr<T, D> u(d) // d是一个可调用的对象，用来释放u指向的T对象

- u = nullptr; //释放指向u的对象，将u置空
- u.release(); //u放弃指向对象的控制权，返回指针，并将u置空
- u.reset(); //释放u指向的对象；
- u.reset(q); 如果提供了q，则令q指向这个对象；否则将u置为空
- u.reset(nullptr)
*/

int main(void)
{
    return 0;
}

void t_unique_ptr()
{
    unique_ptr<double> p1(new double(3.12));
    unique_ptr<int> p2;

    /*
     * unique_ptr不支持拷贝和赋值，只能通过移动构造和移动赋值来交换
     */
    unique_ptr<string> p3(new string("hello"));
    // unique_ptr<string> p4(p3); //错误：unique_ptr不支持拷贝
    // p3 = p2; //错误：unique_ptr不支持赋值

    /*
    - 将所有权从p1转移给p2
    */
    unique_ptr<string> p4(p3.release()); //创建

    unique_ptr<string> p5(new string("world")); //转移
    p4.reset(p5.release());                     //被转移的要进行release

    // p4.release(); //p4不在接管指针，但是原来的指针丢失了；
    auto p6 = p4.release(); //
}
/*
- 将要销毁的unique_ptr可以被拷贝：例如返回值
*/
unique_ptr<int> t_clone(int p)
{
    return unique_ptr<int>(new int(p)); //局部变量，将要被销毁
}
