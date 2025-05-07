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
    list<string> authors = {"Milton", "Shakespeare", "Homer"}; //列表初始化
    list<string> list2(authors);                               //容器类型元素必须匹配
    // deque<string> authList(authors); //错误，容器类型不匹配；
    deque<string> authList(authors.cbegin(), authors.cend());

    vector<const char *> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    deque<string> words2(words2);                              //错误，元素类型不匹配；
    forward_list<string> words3(words.cbegin(), words.cend()); //可以将类型转换成string

    vector<int> v1(10, -1);
    for (auto &i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    list<string> ls(10, "hi"); 
    forward_list<int> fl(10); //单向链表，十个0
    deque<string> dq(10); //双向队列，十个空string
}