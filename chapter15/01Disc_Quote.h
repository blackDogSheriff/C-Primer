#ifndef __DISC_QUOTE_H__
#define __DISC_QUOTE_H__
#include "01Quote.h"
#include <iostream>
using namespace std;

/*
    抽象基类：包含纯虚函数的类
        - 不能用抽象基类来创建对象
        - 抽象基类通常用作接口类，定义接口但不实现接口
*/
class Disc_Quote : public Quote
{
  public:
    Disc_Quote() = default;
    Disc_Quote(const string &book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc){};
    double net_price(size_t) const override = 0;
    void debug() override;

  protected:
    size_t quantity = 0;
    double discount = 0.0;
};

void Disc_Quote::debug()
{
    Quote::debug();
    cout << "quantity = " << quantity << " discount = " << discount << endl;
}
#endif