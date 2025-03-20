#include <iostream>
using namespace std;

inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

int main(void)
{
    return 0;
}

/*
笔记：
    1. 內联函数适用于规模较小，流程直接，频繁调用的函数；
    2. 内联函数直接展开函数体
*/
