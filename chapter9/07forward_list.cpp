#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
/*
- forward_list：单向链表，后面的元素无法获取前面元素的信息
    - c.before_begin();
    - c.cbefore_begin();

    - c.insert_after(p, t);
    - c.insert_after(p, n, t);
    - c.insert_after(p, b, e);
    - c.insert_after(p, il);

    - emplace_after(p, args);
    - c. erase_after(p);
    - c.erase_after(b, e);
*/

void print_forward_list(forward_list<int> &flist);
void t_forward_list();
int main(void)
{
    t_forward_list();
    return 0;
}

void t_forward_list()
{
    forward_list<int> flist = {1, 2, 3, 4, 5};
    print_forward_list(flist);

    forward_list<int>::iterator prev = flist.before_begin();
    forward_list<int>::iterator cr = flist.begin();
    while (cr != flist.end())
    {
        if (*cr % 2)
        {
            cr = flist.erase_after(prev); //删除cr指向的元素，并返回下一个元素
        }
        else
        {
            prev = cr;
            ++cr;
        }
    }
    print_forward_list(flist);
}

void print_forward_list(forward_list<int> &flist)
{
    for (auto &i : flist)
    {
        cout << i << " ";
    }
    cout << endl;
}