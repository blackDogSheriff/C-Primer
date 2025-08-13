#include <iostream>
#include "tt.h"

using namespace std;

int main(void)
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2; // b1的data是一个指针，拷贝了b2的data指针
        b2.push_back("about");
        cout << b2.size() << endl;
    }

    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;

    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << endl;

    cout << b3.front() << " " << b3.back() << endl;

    return 0;
}
