#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std : placeholders;

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for (auto iter = beg; iter != end; iter++)
        cout << *iter << " ";
    cout << endl;
}

void check_size(const string &s, const string::size_type sz)
{
    return s.size() < sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
}

bool five_or_more(const string &s1)
{
    return s1.size() >= 5;
}

int main(void)
{
    vector<string> words = {"the", "quickk", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    output_words(words.begin(), words.end());
    // 获取一个迭代器，指向最后一个满足size() >= 5 的元素之后的位置
    // 将满足条件的排前面
    // auto iter = partition(words.begin(), words.end(), five_or_more);
    auto iter = partition(words.begin(), words.end(), bind(five_or_more, _1, sz);
	output_words(words.begin(), words.end());
	//stable_partition保持元素顺序
	auto iter1 = stable_partition(words.begin(), words.end(), five_or_more);
	output_words(words.begin(), words.end());


	return 0;
}
