#include <iostream>
using namespace std;

//
int main(void)
{
    return 0;
}

#if 0
// initializer_list中对象的元素永远都是常量，无法变变
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;

    return 0;
}
#endif

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl;
}
