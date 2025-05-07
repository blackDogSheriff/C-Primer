#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void t_fill();
void print(const vector<int> &v);

int main(void)
{
    t_fill();
    return 0;
}

void t_fill()
{
    vector<int> v(10);
    fill(v.begin(), v.end(), 1);
    print(v);
}

void print(const vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}