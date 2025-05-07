#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void print_vector(const vector<int> &vec);
int main(void)
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec1;
    replace(vec.begin(), vec.end(), 0, 42);                           // 将0替换成42
    replace_copy(vec.begin(), vec.end(), back_inserter(vec1), 1, 42); //将vec拷贝到vec1中，并将1替换成42

    print_vector(vec);
    print_vector(vec1);

    return 0;
}

void print_vector(const vector<int> &vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
