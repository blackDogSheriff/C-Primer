#include <iostream>
#include <set>
#include <map>

using namespace std;
int
main(void)
{
    map<string, size_t> word_count; // 创建一个空容器
    set<string>         exclude = {"The", "But", "And", "Or", "An", "A",
                                   "the", "but", "and", "or", "an", "a"};
    map<string, string> authors = {
        {"Joyce", "James"}, {"Austen", "Jane"}, {"Dickens", "Charles"}};

    return 0;
}
/*
笔记：
    1. 关联容器不支持顺序容器位置相关的操作，比如push_back
    2. 关联容器也不支持构造函数或者插入操作这些接受一个元素值或者数量值的操作
    3. map或者set中的关键字必须是唯一的，multimap和multiset没有该限制
*/
