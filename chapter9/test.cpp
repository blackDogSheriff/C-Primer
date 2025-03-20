#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> ivec;
	auto iter = ivec.begin();
	int word;
	while(cin >> word)
		iter = ivec.insert(iter, word);
	
	for (auto &i : ivec)
		cout << i << endl;
	return 0;
}
