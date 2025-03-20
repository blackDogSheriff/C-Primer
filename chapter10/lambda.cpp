#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    // ostream对象不能拷贝
    for_each(words.begin(), words.end(), [&os, c](const string &s) { os << s << c; });
    cout << endl;
}

int main(void)
{
    int sz = 42;
    auto f = [sz] { return sz; }; // 创建lambda的时候拷贝sz
    sz = 43;
    cout << f() << endl; // 42

    // lambda可以采用引用的方式捕获变量
    auto f2 = [&sz] { return sz; };
    cout << f2() << endl; // 43
    sz = 10;
    cout << f2() << endl; // 10

    // 可变lambda
    size_t v1 = 42;
    auto f = [v1]() mutable { return ++v1; };
    cout << f() << endl;

    // 隐式捕获
    size_t v2 = 42;
    auto f3 = [=] { return v2; };
    auto f3 = [&] { return v2; };

    // 指定返回类型
    // 默认lambda如果包含除了return之外的语句，则编译器假定此lambda返回void
    // 函数transform接受三个迭代器和一个可调用对象。
    // 前两个迭代器表示输入序列，第三个迭代器表示目的位置。
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) { return i < 0 ? -1 : i; });
    // 有两个return，返回类型为void
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int {
        if (i < 0)
            return -i;
        else
            return i;
    });

    vector<string> words = {"the", "quickk", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4, cout, ' ');
}
