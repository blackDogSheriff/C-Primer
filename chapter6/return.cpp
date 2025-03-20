#include <iostream>
using namespace std;
char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main(void)
{
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'a';

    // 返回数组指针
    typedef int arrT[10];
    using arrT = int[10];
    arrT *func(int i);

    // 返回数组指针的直接定义
    // type (*function(parameter_list))[dimension]
    int(*func(int i))[10];

    // 使用auto
    auto func(int i)->int(*)[10];

    // 使用decltype
    decltype(odd) *arrPtr(int i);

    return 0;
}
