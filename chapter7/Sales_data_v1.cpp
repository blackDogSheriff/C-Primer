#include <iostream>
using namespace std;

struct Sales_data
{

    /*
     * 在类的开始或者结束集中声明友元
     */
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

  public:
    Sales_data() = default;
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p){}; //显示初始化列表
    Sales_data(const string &s) : bookNo(s){}; //剩下两个没有显示初始化的参数按照默认构造函数的规则进行隐式初始化
    Sales_data(istream &is);

    /*
     * - this指针是一个常量指针，不能修改this指针的指向；
     * - 例如：Sales_data *const this；
     * - 这会导致常量对象无法通过this指针调用某些只读的成员函数；
     * - 函数后面添加const，标识this指针类型为 const Sales_data *const
     */
    string isbn() const
    {
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);

  private:
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, Sales_data &);
istream &read(istream &, Sales_data &);

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

/*
 * - 函数内声明，函数外定义，声明和定义一定要相匹配
 */

double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

/*
 * - 外部定义函数无权限直接访问类私有成员，通过将函数在类内部声明成友元函数，实现访问；
 */
ostream &print(ostream &os, Sales_data &item)
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