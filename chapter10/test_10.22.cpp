#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;
inline void output_words(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}
void biggies(vector<string> &words, 
		vector<string>::size_type sz)
{
	output_words(words);
	auto bc = count_if(words.begin(), words.end(),
				bind(check_size, _1, sz));
}
int main(void)
{
	return 0;
}
