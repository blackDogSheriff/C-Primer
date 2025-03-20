#include <iostream>
using namespace std;
class IsShoter
{
  public:
    bool operator()(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
};
class NotShoterThan
{
  public:
    NotShoterThan(int len) : minLen(len)
    {
    }
    bool operator()(const string &str)
    {
        return str.size() >= minLen;
    }

  private:
    int minLen;
};
class PrintString
{
  public:
    void operator()(const string &str)
    {
        cout << str << " ";
    }
};

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    IsShoter is;
    stable_sort(word.begin(), words.end(), is);
}
int main(void)
{
    return 0;
}
