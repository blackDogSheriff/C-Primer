#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
void t_catch();
void t_refer_catch();
int main(void)
{
    t_catch();
    t_refer_catch();

    return 0;
}

void t_catch()
{
    size_t i = 1;
    auto f = [i] { return i; };
    i = 0; //捕获是拷贝，修改不会影响外部
    cout << f() << endl;
}

void t_refer_catch()
{
    size_t i = 1;
    auto f = [&i] { return i; };
    i = 0; //捕获是引用，修改会影响外部
    cout << f() << endl;
}