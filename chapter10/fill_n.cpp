#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> i(10);
    fill_n(i.begin(), i.size(), 0);
    for (auto s : i)
        cout << s << endl;
    return 0;
}
