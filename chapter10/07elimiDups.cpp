#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<string> &vec);
void elim_dups();

int main(void)
{
    elim_dups();
    return 0;
}
void elim_dups()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    print_vector(words);
    sort(words.begin(), words.end());
    print_vector(words);
    auto end_unique = unique(words.begin(), words.end()); // unique：把重复的值扔尾部，返回重复值的开始位置
    print_vector(words);
    words.erase(end_unique, words.end());
    print_vector(words);
}

void print_vector(const vector<string> &vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}