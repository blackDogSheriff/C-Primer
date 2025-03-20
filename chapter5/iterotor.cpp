#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;

    int i;
    while (cin >> i)
        v.push_back(i);
    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end())

        return 0;
}
