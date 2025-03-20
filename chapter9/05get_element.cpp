#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> c = {0, 1, 2, 3, 4, 5, 6, 7};

    if (!c.empty())
    {
        auto val = *c.begin(), val2 = c.front();
        auto last = c.end();

        auto val3 = *(--last);
        auto val4 = c.back(); // front 和back返回的是引用，forward_list不支持（前向链表，只能从前向后访问）
        c[6] = 5;    //返回引用
        c.at(6) = 5; //和上面一样，如果下标越界则抛出异常
    }

    return 0;
}