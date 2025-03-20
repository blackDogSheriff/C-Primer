#include <iostream>
using namespace std;

// 以下三种类型共享一种调用形式
int add(int i, int j)
{
    return i + j;
}

auto md = [](int i, int j) { return i % j; } struct divide
{

    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};
int main(void)
{
    return 0;
}
