#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main(void)
{
    int val1 = 10;
    auto sum = [](const int &a, const int &b) { return a + b; };
    cout << sum(1, 1) << endl;
    auto sum1 = [val1](const int &a) { return val1 + a; };
    cout << sum1(1) << endl;
    return 0;
}
