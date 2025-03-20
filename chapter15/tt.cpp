#include <iostream>
using namespace std;
class Quote { // 基类通常都定一个虚函数
public:
    Quote(const string &book, double sales_price)
        : bookNo(book)
        , price(sales_price)
    {
    }
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
        cout << "bookNo=" << bookNo << "price=" << price << endl;
    }
    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0:
};

class Bulk_quote : public Quote {
public:
    double net_price(size_t cnt) const override
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    size_t min_qty;
    double discount;
};

double
print_total(ostream &os, const Quote &item, size_t n)
{ // 调用类函数返回价格
    double ret = item.net_price(n);
    return ret;
}
int
main(void)
{
    return 0;
}
