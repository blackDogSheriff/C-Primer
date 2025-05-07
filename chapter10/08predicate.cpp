#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
- unary predicate:一元谓词，只接收一个参数
- binary predicate：二元谓词，接收两个参数
*/

void print_vector(const vector<string> &vec);
bool is_shorter(const string &s1, const string &s2);
void elim_dups(vector<string> &vec);

int main(void)
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    print_vector(words);
    sort(words.begin(), words.end(), is_shorter); //为true交换
    print_vector(words);

    elim_dups(words);
    print_vector(words);
    stable_sort(words.begin(), words.end(), is_shorter);
    print_vector(words);

    return 0;
}

void elim_dups(vector<string> &vec)
{
    sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end()); // unique：把重复的值扔尾部，返回重复值的开始位置
    vec.erase(end_unique, vec.end());
}

bool is_shorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void print_vector(const vector<string> &vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
