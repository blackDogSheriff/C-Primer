#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开文件失败！" << endl;
		exit(1);
	}

	vector<pair<string, int>> data;		//创建一个pair
	string s;
	int v;

	while (cin >> s && in >> v)
		data.push_back(pair<string, int>(s, v));
		//data.push_back({s, v});
		//data.push_back(make_pair(s, v));

	
	for (const auto &d : data)
		cout << d.first << " " << d.second << endl;
	return 0;
}
