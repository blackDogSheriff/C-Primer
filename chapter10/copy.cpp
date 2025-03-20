#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int
main(void)
{
    int  a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int  a2[sizeof(a1) / sizeof(*a1)]; // a1和a2的大小一样
    auto ret = copy(begin(a1), end(a1), a2);

    for (auto i : a2)
        cout << i << endl;
    return 0;
}
