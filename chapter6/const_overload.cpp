#include <iostream>
using namespace std;

int main(void)
{
    return 0;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &t(string &s1, string &s2)
{
    auto r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

string &shorterString(string &s1, string &s2)
{
    auto r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

/*
笔记
    1. 候选函数：函数名相同，作用域可见
    2. 可行函数：函数名相同，参数数量相同，参数匹配或者可转换
*/
