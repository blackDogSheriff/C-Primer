#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;
using namespace placeholders;

inline void
output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for (auto iter = beg; iter != end; iter++)
        cout << *iter << " ";
    cout << endl;
}

void
elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool
check_size(const string &s, const string::size_type sz)
{
    return s.size() >= sz;
}

void
biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    // 打印每个单词
    for_each(words.begin(), words.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
    // 将小于sz的单词放在前面，返回一个指向最后一个符合条件元素之后
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    output_words(words.begin(), words.end());
    auto count = wc - words.begin();
}

int
main(void)
{
    vector<string> words = {"the",  "quickk", "red",  "fox", "jumps",
                            "over", "the",    "slow", "red", "turtle"};
    output_words(words.begin(), words.end());
    biggies(words, 5);
    return 0;
}
