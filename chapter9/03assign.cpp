#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
c1 = c2;
c = {a, b, c}; //数组不适用
swap(c1, c2);
c1.swap(c2);

seq.assign(c1, c2);
seq.assign(il); //il为初始化列表
seq.assign(n, t);
 */

int main(void)
{
    list<string> names;
    vector<const char *> oldstyle;
    // names = oldstyle; //错误，类型不匹配
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    list<string> slist1(1); // 1个空string
    slist1.assign(10, "Hiya");

    // swap
    vector<string> svec1(10);
    vector<string> svec2(24);
    //对string调用swap会导致迭代器、引用、指针失效
    // array调用swap会真正交换两者的元素
    swap(svec1, svec2); //元素本身不存在交换，只交换数据结构，类似指针？ 而且迭代器指向的位置不变

    return 0;
}