#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//获取输入字符的长度
class  StrLenIs {
public:
	StrLenIs(int len) : len(len) {}
	bool operator()(const string &str) { return str.length() == len; }	
private:
	int len;
};
class StrLenBetween
{
public:
	StrLenBetween(int minLen, int maxLen) : minLen(minLen), 
		maxLen(maxLen) {}
	bool operator()(const string &str)
	{
		return str.length() >= minLen && str.length() <= maxLen;
	}
private:
	int minLen;
	int maxLen;
};
class StrNotShorterThan
{
public:
	StrNotShorterThan(int len) : minLen(len) {}
	bool  operator()(const string &str) { return str.length() >= minLen; }
private:
	int minLen;
};
void readStr(istream &is, vector<string> &vec)
{
	string word;
	while (is >> word)
		vec.push_back(word);
}
int main(void)
{
	vector<string> vec;
	readStr(cin, vec);
	const int minLen = 1;
	const int maxLen = 10;
	for (int i = minLen; i <= maxLen; i++)
	{
		StrLenIs slenIs(i);
		//将类当作函数使用
		cout << "len : " << i << ", cnt :" << count_if(vec.begin(), vec.end(), StrLenIs) << endl;

	}
	return 0;
}
