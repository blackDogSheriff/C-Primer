#include <iostream>
#include <list>
#include <vector>

using namespace std;
int main(void)
{
	list<string> slist;
	vector<string> v = { "quasi", "simba", "frollo", "scar" };
	slist.insert(slist.begin(), v.end() - 2, v.end());
	slist.insert(slist.end(), { "these", "words", "will", "go", "at", "the", "end" });
	for (auto i : slist)
		cout << i << " ";
	cout << endl;
	return 0;
}
