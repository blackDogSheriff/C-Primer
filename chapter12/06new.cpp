#include "04StrBlob.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    return 0;
}

void t_new()
{
    int *p1 = new int(42);
    string *p2 = new string("hi");
    int *p3 = new int; // 指向一个没有初始化的int

    string *p4 = new string(10, '9'); // 指向一个初始化为10个'9'的string
    // 列表初始化
    vector<int> *p5 = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 内置类型需要进行值初始化
    string *p6 = new string;   // 默认初始化为空
    string *p7 = new string(); // 值初始化为空
    int *p8 = new int;         // 默认初始化为未定义
    int *p9 = new int();       // 值初始化为0

    StrBlob p10 = StrBlob(); // 默认初始化为空
    auto p11 = new auto(p10);
    // auto p12 = new auto{p10, p9}; //错误，只有有单个初始化器

    const int *p13 = new const int(42);   // 指向一个初始化为42的const int
    const string *p14 = new const string; // 指向一个初始化为空的const string
}