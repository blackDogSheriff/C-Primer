#include <iostream>
using namespace std;

// struct默认权限从public开始，class默认权限从private开始，直到遇到下一个访问控制符
class Sales_data
{
    // 非友元函数不可以访问类的私有成员
    // 友元声明只能出现在类的内部，但是具体位置不限
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);
    friend istream &read(istream &, Sales_data &);

  public: // 访问控制符，可以有多个，范围到下一个访问控制符
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s){};
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){};
    Sales_data(istream &);

    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &);

  private:
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    };
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 许多编译器并没有强制限定友元函数必须在使用之前在类的外部也声明
#if 0
Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);
#endif

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

int main(void)
{
    Sales_data Sd("dsjakldjsladj");
    cout << Sd.isbn() << endl;
    return 0;
}

/*
笔记：
    1. 封装
*/
