#include <iostream>
using namespace std;

int main(void)
{
    string str("some string");

    // 每次迭代都会把str的下一个字符拷贝到c中
    for (auto c : str)
    {
        cout << c << endl;
    }

    string s("Hello World !!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)
    {
        if (ispunct(c))
            ++punct_cnt;
    }

    cout << "punctuation characters in " << s << endl;

    return 0;
}
void for_each_string(const string &s)
{
    char c;
    for (size_t i = 0; i < s.length(); ++i)
    {
        c = s[i];
        cout << c << endl;
    }
    return;
}

void auto_for(const string &s)
{
    for (auto &c : s)
    {
        cout << toupper(c) << endl;
    }
}