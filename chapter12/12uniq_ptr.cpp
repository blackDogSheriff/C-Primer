#include <iostream>
#include <memory>
using namespace std;
/*
- unique_ptr<T> u1 // u1是一个空的unique_ptr，指向类型为T的对象；u1使用delete释放它的指针；
- unique_ptr<T, D> u2 //使用类型为D的可调用对象来释放指针
- unique_ptr<T, D> u(d)  //使用对象d来释放

- u = nullptr //将u置空，释放u指向的对象
- u.release() //仅仅切断u和它指向的对象的联系，返回指向该对象的指针，u指向nullptr，但是不会释放内存
- u.reset() //释放u指向的对象，u指向nullptr
- u.reset(p) //释放u指向的对象，u指向p
- u.reset(nullptr) //释放u指向的对象，u指向nullptr
*/

int main()
{

    return 0;
}

void unique_ptr_init()
{
    unique_ptr<int> p1;
    unique_ptr<int> p2(new int(42));                    // 创建一个unique_ptr，管理一个int对象
    unique_ptr<string> p3(new string("Hello, World!")); // 创建一个unique_ptr，管理一个string对象
    // unique_ptr<stirng> p4(p3); //错误，不能拷贝unique_ptr，只能指向一个
    unique_ptr<string> p5;
    // p5 = p3; //错误，unique_ptr不能被赋值，只能移动
}

void unique_ptr_move()
{
    unique_ptr<string> p1(new string("Hello, World!"));
    unique_ptr<string> p2(p1.release()); // p2接管p1的所有权，p1置空

    unique_ptr<string> p3(new string("New String"));
    p2.reset(p3.release()); // p2接管p3的所有权，p3置空，释放p2原来的对象
}

void unique_ptr_release()
{
    unique_ptr<int> p1(new int(53));
    // p1.release(); //仅仅切断联系，返回原指针，不会释放对象
    auto *p2 = p1.release(); // p1指向nullptr，p2指向原来的对象
    delete p2;               // 需要手动释放p2指向的对象
}

unique_ptr<int> unique_ptr_clone(int p)
{
    //要返回的对象即将被销毁，因此编译器尅返回
    return unique_ptr<int>(new int(p)); //返回一个unique_ptr
}