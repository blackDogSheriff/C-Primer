#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    int *ptr = new int(42);
    shared_ptr<int> p1(ptr, [](int *p) { delete p; });
    shared_ptr<int> p2(ptr, [](int *p) { delete p; });
    cout << "p1 use count: " << p1.use_count() << endl; // 输出引用计数
    cout << "p2 use count: " << p2.use_count() << endl;

    return 0;
}
