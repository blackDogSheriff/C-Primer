#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int
main(void)
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec1;
    // 将0替换成42
    replace(vec.begin(), vec.end(), 0, 42);
    replace_copy(vec.begin(), vec.end(), back_inserter(vec1), 1, 42);

    for (auto i : vec)
        cout << i << endl;

    for (auto i : vec1)
        cout << i << endl;
    return 0;
}
