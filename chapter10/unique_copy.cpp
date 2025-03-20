#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void print(const vector<int> &vi)
{
	for (auto &i : vi)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	vector<int> vi = { 1, 2, 7, 4, 9, 6, 7, 8, 9, 10 };
	print(vi);
	list<int> li;
	sort(vi.begin(), vi.end());
	print(vi);
	unique_copy(vi.begin(), vi.end(), back_inserter(li));

	for (auto &v : li)
		cout << v << " ";
	cout << endl;

	return 0;
}
