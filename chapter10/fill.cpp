#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int
main(void)
{
    vector<int> i(10);
    fill(i.begin(), i.end(), 0);
    for (auto s : i)
        cout << s << endl;
    return 0;
}
