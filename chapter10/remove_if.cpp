#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main(void)
{
    remove_if(v1.begin(), v1.end()), [](int i) { return i % 2; };
    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i) { return i % 2; });
    return 0;
}
