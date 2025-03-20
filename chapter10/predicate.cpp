#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void print(vector<string> &words)
{
    for (auto s : words)
        cout << s << " ";
    cout << endl;
}

void elimDups(vector<string> &words)
{
    // 按照字典排序
    sort(words.begin(), words.end());
    // 重排输入范围，使得每个单词只出现一次
    // 排列在范围的前面，返回指向不重复区域最后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    // 移除后面重复的迭代器
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(void)
{
    vector<string> words = {"the", "quickk", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    print(words);
    // 先按照长度排序，然后按照字典排序
    stable_sort(words.begin(), words.end(), isShorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    print(words);
    return 0;
}
