#include <iostream>
#include <set>
#include <map>

using namespace std;

void t_set();
int main(void)
{
    t_set();
    return 0;
}

void t_set()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
    {
        //如果不在排除列表中，则进行计数
        if (exclude.find(word) == exclude.end())
        {
            ++word_count[word];
        }
    }
}
