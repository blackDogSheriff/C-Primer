#include <iostream>
using namespace std;

class ShoterString
{
  public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s.size() < s2.size();
    }

  private:
};

/*
stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
    { return a.size() < b.size(); });
stable_sort(word.begin(), word.end(), ShoterString());
*/

class SizeComp
{
    SizeComp(size_t n) : sz(n)
    {
    }
    bool operator()(const string &s) const
    {
        return s.size() >= sz;
    }
};

auto wc = find_if(word.begin(), words.end(), [sz](const string &s) { return a.size() >= sz; });
auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
int main(void)
{
    return 0;
}
