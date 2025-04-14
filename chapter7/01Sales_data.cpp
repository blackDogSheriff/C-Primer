#include <iostream>
using namespace std;
/*
- 成员函数默认情况下都是内联的，包括构造函数
-
*/

class Sales_data
{
    /*
    - 友元函数
        - 可以访问类的私有成员；
        - 声明在类的位置不限，一半在开头或者结尾统一声明
    */
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend ostream &print(ostream &os, const Sales_data &item);
    friend istream &read(istream &is, Sales_data &item);

  public:
    Sales_data() = default;
    Sales_data(istream &is);
    Sales_data(const string &s) : bookNo(s){}; //剩余俩参数使用类内初始值
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}; //值初始化列表

    string isbn() const
    {
        return bookNo; //通过this指针调用
    }

    Sales_data &combine(const Sales_data &rhs); //合并总收入和售卖总数量
    double avg_price() const;

  private:
    string bookNo;
    unsigned units_sold = 0; //售卖的总量
    double revenue = 0.0;    //总收入
};

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
ostream &print(ostream &os, const Sales_data &item);
istream &read(istream &is, Sales_data &item);

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

int main(void)
{
    return 0;
}