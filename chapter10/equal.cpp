#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
    // roster1和roster2的元素类型不需要完全相同
    // roster2序列元素要大于等于第一个大小
    equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    return 0;
}
