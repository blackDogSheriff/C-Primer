#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开文件失败！！" << endl;
		exit(1);
	}

	vector<pair<string, int>> data;
	string s;
	int v;

	while(in >> s && in >> v)
		data.push_back(pair<string, int>(s, v));
	for (const auto &w : data)
		cout << w.first << " " << w.second << endl;
	return 0;
}

