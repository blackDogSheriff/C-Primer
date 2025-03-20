#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool l_v_equal(vector<int> &ivec, list<int> &ilist) {
	if (ilist.size() != ivec.size())
		return false;
	auto lb = ilist.cbegin();
	auto le = ilist.cend();
	auto vb = ivec.cbegin();
	for (; lb != le; lb++, vb++)
		if (*lb != *vb)
			return false;
	return true;	
}

int main(void)
{
	vector<int> ivec = {1,2,3,4,5,6,7};
	vector<int> ivec1 = {1,2,3,4,5,6,7};
	vector<int> ivec2 = {1,2,3,4,5};
	vector<int> ivec3 = {1,2,3,4,5,6,7,8};
	vector<int> ivec4 = {1,2,3,4,5,6,7,8};

	cout << (ivec == ivec1) << endl;
	cout << (ivec == ivec2) << endl;
	cout << (ivec == ivec3) << endl;
	cout << (ivec == ivec4) << endl;

	ivec1.push_back(8);
	ivec1.pop_back();

	cout << ivec1.capacity() << " " << ivec1.size() << endl;
	cout << (ivec == ivec1) << endl;
	return 0;
}
