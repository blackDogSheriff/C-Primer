#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
- lambda表达式
    - [capture list](parameter list) > reutrn type {function body}
    - 可以忽略参数列表和返回值类型：
        - 如果没有参数列表，使用空括号()，标识没有参数
        - 如果没有返回值类型，则lambda根据代码自动推断返回值类型
        - 如果函数体包含任何单一return之外的语句，且未指定返回值类型，则返回void
*/

void elim_dups(vector<string> &words);
void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = '-');
bool is_shorter(const string &s1, const string &s2);
int main(void)
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os, char c)
{
    elim_dups(words);
    // stable_sort(words.begin(), words.end(), is_shorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    //捕获值
    auto wc1 = find_if(words.begin(), words.end(), [=](const string &a) { return a.size() >= sz; });
    //引用捕获
    auto wc2 = find_if(words.begin(), words.end(), [=](const string &a) { return a.size() >= sz; });

    for_each(wc, words.end(), [&os, c](const string &a) { os << a << c; });
    cout << endl;
}

void elim_dups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end()); // unique：把重复的值扔尾部，返回重复值的开始位置
    words.erase(end_unique, words.end());
}

bool is_shorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}