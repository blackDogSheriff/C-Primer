#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
int main(void)
{
    auto result = find(vec.cbegin(), vec.cend(), val);
    string val = "a value";
    auto result = find(lst.cbegin(), lst.cend(), val);

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int *result = find(begin(ia), end(ia), val);

    auto result = find(ia + 1, ia + 4, val);

    return 0;
}
