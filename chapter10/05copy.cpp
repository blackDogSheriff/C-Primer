#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void print_copy(int (*a)[5]);
int main(void)
{
    int a1[] = {1, 2, 3, 4, 5};
    int a2[sizeof(a1) / sizeof(*a1)];

    auto ret = copy(begin(a1), end(a1), begin(a2));

    print_copy(&a2);
}

void print_copy(int (*a)[5])
{
    for (auto i : *a)
        cout << i << " ";
    cout << endl;
}
