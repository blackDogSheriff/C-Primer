#include <iostream>
#include <algorithm>
#include <numeric>

int main(void)
{
    return 0;
}

void mutable_lambda()
{
    size_t v = 32;
    //默认情况下，被拷贝的的变量，lambda不会改变其值
    //如果希望改变，则必须在参数列表首加上关键字mutable
    auto f = [v]() mutable { return ++v; };
    v = 0;
    auto j = f();
}

void mutable_lambda_2()
{
    size_t v = 32;
    auto f = [&v]() { return ++v; };
    v = 0;
    auto j = f(); // 1
}