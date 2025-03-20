#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void add_child(map<string, vector<pair<string, string>>> &families,
			const string &family, const string &child, const string 
	&birthday)
{
	families[family].push_back(make_pair(child, birthday));
}

int main(void)
{
	map<string, vector<pair<string, string>>> families;
	add_child(families, "章", "老二", "1930-1-1");
	add_child(families, "刘", "老三", "19960621");
	add_child(families, "章", "老四", "1997-12-1");
	add_child(families, "刘", "老五", "19980123");
	
	for (auto const &f : families)
		for (auto const &c : f.second)
			cout << f.first << c.first << " " << c.second << endl;

	return 0;
}

