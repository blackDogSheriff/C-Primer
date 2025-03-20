#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

//创建家族-姓
#if 0
void add_family(map<string, vector<string>> &families, 
			const string &family)
{
	if (families.find(family) == families.end())
		families[family] = vector<string>();
}
#endif

void add_child(map<string, vector<string>> &families,
			const string &family, const string &child)
{
	families[family].push_back(child);
}


int main(void)
{
	map<string, vector<string>> families;
	add_child(families, "章", "老二");
	add_child(families, "刘", "老三");
	add_child(families, "章", "老四");
	add_child(families, "刘", "老五");

	for (const auto &f : families) {
		for (const auto &c : f.second)
			cout << f.first << c << endl;
	}
	return 0;
}
