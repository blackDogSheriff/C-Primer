#include <iostream>
using namespace std;
typedef int (*Func)(int, int);

int
main(void)
{
    vector<Func>;

    int Func(int a, int b)
    {
        return a + b;
    }

    vector<decltype(Func) *> v2;
    return 0;
}
