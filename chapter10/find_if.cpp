#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

string make_plural(int count, const string &s, const string &s1)
{
    if (count > 0)
        return s + s1;
    else
        return s;
}

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    // 也可以使用bind
    // 只能接受一元谓词
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    auto count = words.end() - wc;
    // cout << count << " " << make_plural(count, "word", "s")
    //		<< " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &a) { cout << a << " "; });
    cout << endl;
}

int main(void)
{
    vector<string> words = {"the", "quickk", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    print(words);
    return 0;
}
