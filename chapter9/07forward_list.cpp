#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

void print(forward_list<int> &fi);
int main(void)
{

    /*
    forward_list只能操作之后的元素
    */
    vector<int> vi = {0, 1, 2, 3, 4, 5};
    auto b = vi.begin();
    auto e = vi.end();

    forward_list<int> fi;

    fi.insert_after(fi.before_begin(), 1);
    print(fi);
    fi.insert_after(fi.before_begin(), 10, 5);
    print(fi);
    fi.insert_after(fi.before_begin(), b, e);
    print(fi);
    fi.insert_after(fi.before_begin(), {1, 2, 3});
    print(fi);

    //  emplace_after(p, args); 使用args构造一个对象传递
    fi.emplace_after(fi.before_begin(), 3);
    print(fi);

    fi.erase_after(fi.begin());
    print(fi);
    fi.erase_after(fi.begin(), fi.end());
    print(fi);

    return 0;
}
void print(forward_list<int> &fi)
{
    for (auto &i : fi)
    {
        cout << i << " ";
    }
    cout << endl;
}
