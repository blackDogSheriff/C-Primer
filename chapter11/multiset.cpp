#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
int main(void)
{
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	//iset包含来自ivec中的不重复的元素
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;
	return 0;
}
