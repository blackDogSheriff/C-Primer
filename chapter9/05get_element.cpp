#include <iostream>
#include <vector>
using namespace std;
/*
- 返回引用的：
    - c.back() 返回尾元素（若c为空，函数行为未定义）
    - c.front() 返回首元素（若c为空，函数行为未定义）
    - c.at(n) 返回下标为n的元素的引用，如果下标越界，则抛出oor

- c[n] 返回c中下标为n的元素

*/

int main(int argc, char **argv)
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto val = *v.begin(), val2 = *v.end();
    auto last = v.end();
    auto val3 = *(--last);
    auto val4 = v.back();

    v.front() = 100;
    auto &vr = v.back();
    vr = 200;
    auto v2 = v.back(); // v2不是一个引用
    v2 = 0; //没有改变容器里面的值

    return 0;
}
