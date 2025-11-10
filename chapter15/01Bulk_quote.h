#ifndef __BULK_QUOTE_H__
#define __BULK_QUOTE_H__

#include <iostream>
#include "01Disc_Quote.h"

using namespace std;

class Bulk_Quote : public Disc_Quote
{
  public:
    Bulk_Quote() = default;
    Bulk_Quote(const string &, double, size_t, double);
    double net_price(size_t) const override; //省略virtual；显示override指明覆写
};

Bulk_Quote::Bulk_Quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
    : Disc_Quote(book, sales_price, qty, disc_rate){};

double Bulk_Quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif // __BULK_QUOTE_H__