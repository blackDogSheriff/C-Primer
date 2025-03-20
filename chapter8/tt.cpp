#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ifstream in("data");
	if (!in) {
		cerr << "无法打开输入" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();
	auto it = words.begin();
	while (it != words.end()) {
		cout << *it << endl;
	}
	return 0;
}
