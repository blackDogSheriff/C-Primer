#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
    forward_list有自己专门的版本的insert和emplace；
    forward_list不支持push_back和emplace_back
    vector和string不支持

    c.push_back(t);
    c.emplace_back(args);

    c.push_front(t);
    c.emplace_front(args);

    c.insert(p, t);
    c.emplace(p, args);

    c.insert(p, n, t);
    c.insert(p, b, e);
    c.insert(p, il);
*/
int main(void)
{
    string word;
    while (cin >> word)
    {
    }
    return 0;
}

void t_push_back()
{
}

void t_push_front()
{
    // deque可以随机访问，也可以push_front
    list<int> il;
    for (size_t ix = 0; ix != 4; ++ix)
    {
        il.push_front(ix);
    }
}

void t_insert()
{
    vector<string> sv;
    list<string> sl;
    sl.insert(sl.begin(), "hello");
    sv.insert(sv.begin(), "hello"); // vector中间调用insert耗时高
    sv.insert(sv.end(), 10, "hello");

    vector<string> sv2;
    sl.insert(sl.begin(), sv2.begin(), sv2.end());
    sl.insert(sl.end(), {"hello", "world"});

    // sl.insert(sl.begin(), sl.begin(), sl.end()); //运行时错误，不能指向与目的位置相同的容器

    /*
    - 接收元素个数或者范围的insert返回第一个新加入的元素的迭代器
    - 通过使用insert返回值，可以在容器中一个特定位置反复插入元素
    */

    list<string> sl2;
    auto it = sl2.begin();
    string word;
    while (cin >> word)
    {
        it = sl2.insert(it, word);
    }
}

void t_emplace()
{
    list<string> sv;
    sv.emplace_back("hello"); //使用“hello”构造了一个对象并放到sv尾部
    sv.emplace_back();        //默认构造函数
    sv.emplace_front("hello");
    sv.emplace(sv.begin(), "word");
}

/*
笔记：
    1. 在一个vector或者string尾部之外任何位置,
或者deque的首位之外的任何位置添加元素都要移动元素
        向一个vector或者string添加元素可能引起整个对象的存储空间重新分配
        重新分配一个对象的存储空间需要分配新的内存，并且将元素从旧的空间移动到新的空间
    2. 调用emplace成员函数的时候，则是将参数传递给元素类型的构造函数
        简单说就是使用元素类型的构造函数构造一个元素，添加到相应的位置

*/
