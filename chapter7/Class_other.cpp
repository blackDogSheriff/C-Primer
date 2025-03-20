#include <iostream>
using namespace std;
struct First
{
    int memi;
    int getMem();
};
struct Second
{
    int memi;
    int getMem();
};

int main(void)
{
#if 0
    // 错误，不同类不可以拷贝
    // First obj1;
    // Second obj2 = obj1;
    First item1;
    class First item1; // 等价声明
    // 前向声明：已知为类类型，但是不清除包含哪些成员，在定义之前是不完全类型
    // 一旦类名出现过，就认为类声明过，因此类允许包含指向它自身类型的引用或者指针
    class Link_screen
    {
        Screen window;
        Link_screen *next;
        Link_screen *prev;
    };
    // 友元函数可以定义在类的内部,但是也需要在类的外部声明，否则外部无法使用
    // 名字查找和类的作用域
    // 名字声明：类似变量从内向外查找
    // 类的定义：1.编译成员声明 2.编译函数
    // 编译器处理完类中的全部声明之后才会处理成员函数中的定义

    // 构造函数初始值必须初始化
    class ConstRef
    {
      public:
        ConstRef(int ii);
        // 初始化顺序只和类中定义的顺序有关
        ConstRef(int ii) : i(ii), ci(ii), ri(i)
        {
        }

      private:
        int i;
        const int ci;
        int &ri;
    };
    ConstRef::ConstRef(int ii)
    {
        i = ii;
        ci = ii;
        ri = i;
    }
#endif
    return 0;
}
