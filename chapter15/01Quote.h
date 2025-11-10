#ifndef __QUOTE_H__
#define __QUOTE_H__
#include <iostream>
using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price){};
    string isbn() const
    {
        return bookNo;
    }

    virtual double net_price(size_t n) const
    {
        return n * price;
    }

    virtual void debug()
    {
        cout << "bookNo = " << bookNo << " price = " << price << endl;
    }

    virtual ~Quote() = default;

  private:
    string bookNo;

  protected:
    double price = 0.0;
};

#endif // __QUOTE_H__