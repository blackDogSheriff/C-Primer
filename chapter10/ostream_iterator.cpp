#include <iostream>
using namespace std;
int main(void)
{
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec) // 将vec中所有的元素写到cout
        *out_iter++ = e;
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
    return 0;
}
