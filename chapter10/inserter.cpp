#include <iostream>
#include <list>
#include <vector>

using namespace std;

void print(const list<int> &ls)
{
    for (auto &s : ls)
        cout << s << " ";
    cout << endl;
}

using namespace std;
int main(void)
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3 = {2, 2};
    // 将元素逐个插入到最前面
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    print(lst2);
    // 将元素拷贝到首位
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    // it = lst3.insert(it, val);
    //++it;
    print(lst3);
    return 0;
}
