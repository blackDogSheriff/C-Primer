#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> i;

    auto it = back_inserter(i);

    *it = 42;
    *it = 2;
    *it = 5;

    fill_n(back_inserter(i), 10, 3);
    for (auto s : i)
        cout << s << endl;
    return 0;
}
