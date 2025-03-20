#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

void print(const string &a)
{
    for (auto it = a.crbegin(); it != a.crend(); ++it)
        cout << *it;
    cout << endl;
}

int main(void)
{
    string line("FIRST,MIDDLE,LASE");
    print(line);
    // auto获取一个反向迭代器
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(line.crbegin(), rcomma) << endl;
    // c属性
    cout << string(rcomma.base(), line.cend()) << endl;
    return 0;
}
