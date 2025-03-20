#include <iostream>
using namespace std;

int main(void)
{
    double price = 109.99, discount = price * 0.16;
    // double salePrice = applyDiscount(price, discount);
    // list initialization
    int units_sold0 = 0;
    int units_sold1 = {0};
    int units_sold2{0};
    int units_sold3(0);

    // default initialization : 静态存储初始化为0，其他为随机值；
}