#include <iostream>
#include <list>
using namespace std;
/*
- c.pop_back(); //删除c中的元素，若c为空，则函数行为未定义。函数返回void；
    - forward_list不支持
- c.pop_front(); //删除c中的元素，若c为空，则函数行为未定义。函数返回void；
    - vector、string不支持
- c.erase(b,e);
- c.clear();
*/

int main(void)
{
    list<string> ls = {"hello", "world", "!"};
    while (!ls.empty())
    {
        ls.pop_back();
    }
    return 0;
}

void t_erase()
{
    list<int> ls = {1, 2, 3, 4, 5};
    list<int>::iterator it = ls.begin();
    while (it != ls.end())
    {
        if (*it % 2)
        {
            it = ls.erase(it);
        }
        else
        {
            ++it;
        }
    }
}