#include <iostream>
#include <map>
#include <set>

using namespace std;
int main(void)
{
#if 0
	map<string, size_t> word_count;
	auto map_it = word_count.begin();
	cout << map_it->first;
	cout << " " << map_it->second;
	map_it->first = "new key";		//错误，first是const的
	++map_it->second;	//递增值
	return 0;

	set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end()) {
		*set_it = 42;		//错误*set_it中的关键字是只读的
		cout << *set_it << endl;
	}
#endif
}
