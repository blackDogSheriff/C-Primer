#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;
int main(void)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int val = 8;
    auto result = find(v.cbegin(), v.cend(), val);

    string str = "a";
    list<string> lst = {"a", "b", "c", "d", "e"};
    auto result = find(lst.cbegin(), lst.cend(), str);

    int ia[] = {1, 2, 3, 4, 5};
    int *p = find(begin(ia), end(ia), 3);

    return 0;
}
