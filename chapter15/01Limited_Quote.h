#ifndef __LIMITED_QUOTE_H__
#define __LIMITED_QUOTE_H__

#include <iostream>
#include "01Disc_Quote.h"

using namespace std;

class Limited_Quote : public Disc_Quote
{
  public:
    Limited_Quote() = default;
    Limited_Quote(const string &book = "", const double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
        : Disc_Quote(book, sales_price, qty, disc_rate){};

    double net_price(size_t cnt) const override
    {
        if (cnt <= quantity)
            return cnt * (1 - discount) * price;
        else
            return (quantity * (1 - discount) + (cnt - quantity)) * price;
    }
};

#endif // __LIMITED_QUOTE_H__