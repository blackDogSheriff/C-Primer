#include "04StrBlob.h"
#include <iostream>
using namespace std;
int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2; // b1和b2元素共享
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;
    return 0;
}
