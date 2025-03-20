#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> iv;
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;

    for (vector<int>::size_type i = 0; i != 24; ++i)
    {
        iv.push_back(i);
    }
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;

    //如果大于size，则设置，否则忽略
    iv.reserve(50);
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;

    while (iv.size() != iv.capacity())
    {
        iv.push_back(0); //没有超过50就不会重新进行分配
    }
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;

    iv.push_back(0); //此时capacity大于size需要进行重新分配
    //发现空间直接进行了翻倍
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;

    iv.shrink_to_fit(); //有可能会被忽略
    cout << " capacity: " << iv.capacity() << " size: " << iv.size() << endl;
}