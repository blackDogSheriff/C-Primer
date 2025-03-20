#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
    forward_list有自己专门的版本的insert和emplace；
    forward_list不支持push_back和emplace_back

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
    // 所有的顺序容器都支持push_back
    string word;
    list<string> container;
    while (cin >> word)
        container.push_back(word);

    // list,forward_list,deque支持push_front
    list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix)
        ilist.push_front(ix);

    // vector,deque, list, string支持insert
    // 可以在任意位置插入
    list<string> slist;
    auto iter = slist.cbegin();
    slist.insert(iter, "Hello!");
    slist.insert(slist.begin(), "Hello");

    vector<string> svec;
    svec.insert(svec.end(), 10, "Anna");
    slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});

    // insert返回指向第一个新加入元素的迭代器
    list<string> lst;
    auto it = lst.begin();
    while (cin >> word)
        it = lst.insert(it, word); // 等价调用push_front，insert返回指向第一个新加入的元素的迭代器

    list<int> il = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << *(il.end()--) << endl;

    return 0;
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
