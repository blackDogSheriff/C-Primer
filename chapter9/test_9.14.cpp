#include <iostream>
#include <vector>
#include <list>

using namespace std;

int
main(void)
{
    list<const char *> slist = {"hello", "world", "!"};
    vector<string>     svec;

    // 容器类型不同，不能直接赋值
    // sevc = slist;	//直接赋值需要容器类型和元素类型完全一样

    svec.assign(slist.begin(), slist.end());

    cout << svec.capacity() << " " << svec.size() << " " << svec[0] << " "
         << svec[svec.size() - 1] << endl;

    return 0;
}
