#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
using namespace namespace_name;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main(void)
{
    string s = "hello";
    auto check6 = bind(check_size, _1, 6);
    bool b1 = check6(s);
    auto wc = find_if(words.begin(), word.end(), 
				[sz](const string &a);
	auto wc = find_if(words.begin(), words.end(),
				bind(check_size, _1, sz));
	return 0;
}
