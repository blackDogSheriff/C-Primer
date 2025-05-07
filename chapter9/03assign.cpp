#include <iostream>
#include <vector>
#include <list>
#include <string>
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

void print(const list<string> &ls);
int main(void)
{
    list<string> names = {"Milton", "Shakespeare", "Homer"}; //列表初始化
    vector<const char *> oldstyle = {"the"};
    //    names = oldstyle; //错误，类型不匹配

    names.assign(oldstyle.cbegin(), oldstyle.cend()); //元素替换
    print(names);
    list<string> slist1(1);
    slist1.assign(10, "a");

    return 0;
}

void print(const list<string> &ls)
{
    for (auto &i : ls)
    {
        cout << i << " ";
    }
    cout << endl;
}