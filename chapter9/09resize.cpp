#include <iostream>
#include <list>
using namespace std;
/*
- array不支持resize
- c.resize(n); //将容器的大小调整为n
   - 如果当前大小大于所要求的大小，容器后部的元素会删除
   - 如果当前大小小于所要求的大小，会将新的元素添加到容器后部
- c.resize(n, t); //用t填充

*/
void print_list(list<int> &il);
void t_resize();
int main(int argc, char **argv)
{
    t_resize();
    return 0;
}

void t_resize()
{
    list<int> il = {1, 2, 3, 4, 5};
    print_list(il);
    il.resize(15); //扩容到15个，用0填充
    print_list(il);
    il.resize(3);
    print_list(il);
    il.resize(25, -1); //扩容到25个，用-1填充
    print_list(il);
}

void print_list(list<int> &il)
{
    for (auto &i : il)
    {
        cout << i << " ";
    }
    cout << endl;
}