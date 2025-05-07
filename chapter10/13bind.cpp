#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

//不能作为find_if的参数，因为find_if需要一个一元谓词，这个是二元的
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

/*
- bind：
    - 接收一个可调用对象，生成一个新的可调用对象来适应原对象的参数列表
    - auto newCallable = bind(callable, ars_list);
*/

int main(void)
{
    auto check6 = bind(check_size, _1, 6); //一个可调用对象，接受一个string和int

    string s = "hello";
    bool b1 = check6(s); // check6会调用check_size(s, 6)

    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, 6));

    int sz = 4;
    auto wc1 = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });

    sort(words.begin(), words.end(), bind(isShorter, _1, _2));
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));
    return 0;
}

ostream &print(ostream &os, const string &s, char c);
void t_bind_refer()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    char c = ' ';
    ostream &os = cout;
    for_each(words.begin(), words.end(), [&os, c](const string &a) { os << a << c; });
    // for_each(words.begin(), words.end(), bind(print, ref(os), _1, c));
    for_each(words.begin(), words.end(), bind(print, ref(os), _1, c));
}

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}
