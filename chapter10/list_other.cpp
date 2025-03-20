#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

inline void output_words(list<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

void elimDups(list<string> &words)
{
    output_words(words);

    // 字典排序
    words.sort();
    output_words(words);
    // 去重
    words.unique();
    output_words(words);
    // 只有sort要求下标访问
    auto unique_ptr = unique(words.begin(), words.end());
    output_words(words);
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "文件打开失败！" << endl;
        exit(1);
    }

    list<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    elimDups(words);
    return 0;
}
