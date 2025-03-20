#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;
/*
- init:
    - C c; //默认初始化
    - C c{1,2,3,4,5}; //列表初始化
    - C c = {1,2,3,4,5};
    - C seq(n); //含有n个元素
    - C seq(n, t); //含有n个t元素
- copy init:
    - C c1(c2); //c1和c2必须类型相同，如果是array，两者大小还必须相同
    - C c1 = c2;
    - C c{b, e}; //使用范围进行初始化
 */

int main(void)
{
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char *> articles = {"a", "an", "the"};

    list<string> list2(authors);
    // deque<string> authList(authors); //错误，容器类型不匹配
    // vector<string> words(authList);

    forward_list<string> words(articles.begin(), articles.end());
}