#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void print(const vector<string> &words)
{
    for (auto s : words)
        cout << s << " ";
    cout << endl;
}
void elimDups(vector<string> &words)
{
    print(words);
    // 按照字典排序
    sort(words.begin(), words.end());
    print(words);
    // 重排输入范围，使得每个单词只出现一次
    // 排列在范围的前面，返回指向不重复区域最后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    print(words);
    // 移除后面重复的迭代器
    words.erase(end_unique, words.end());
    print(words);
}
int main(void)
{
    vector<string> words = {"the", "quickk", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    return 0;
}
