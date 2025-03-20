#include <iostream>
#include <vector>
#include <utility>

using namespace std;
pair<string, int> process(vector<string> &v)
{
	if (!v.empty())
	{
		return {v.back(), v.back().size()};
		//显式构造pair对象
		return pair<string, int>(v.back(), v.back().size());
		//使用make_pair来生成pair对象
		return make_pair(v.back(), v.back().size());
	}
	else
		return pair<string, int>();
}
int main(void)
{
	return 0;
}
