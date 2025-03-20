#include <iostream>
using namespace std;

//非成员函数接口
class Sales_data
{
    //友元不受类的访问控制符限制
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend ostream &print(ostream &, Sales_data &);
    friend istream &read(istream &, Sales_data &);

  public:
#if 0
    //构造函数
    Sales_data() = default;
    //提供默认实参的构造函数需要再看看
    Sales_data(string s = "") : bookNo(s){};
    Sales_data(const string &s) : bookNo(s){};
#endif
    //初始化成员
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p){};
    //委托构造函数，委托给另一个函数取构造
    Sales_data() : Sales_data("", 0, 0){};
    // explicit只对一个实参的构造函数有效，需要多个实参的构造函数不能用于执行隐式类型转换
    // 只需要再声明的时候就可以，不应该再定义的时候也添加explicit关键字
    explicit Sales_data(string s) : Sales_data(s, 0, 0){};

    //首先委托给默认构造函数，然后默认构造函数委托给了三参数的构造函数，最后再执行构造函数体的内容
    //当一个构造函数委托给另一个构造函数的时候，受委托的构造函数的初始值列表和函数体依次执行，然后控制权才会还给委托者的函数体
    explicit Sales_data(istream &is) : Sales_data()
    {
        read(is, *this);
    }

#if 0
    //对数据成员进行赋值操作，而不是初始化，如果某个成员是const类型，则必须进行初始化
    Sales_data(const string &s, unsigned n, double p)
    {
        bookNo = s;
        units_sold = n;
        revenue = p;
    }
#endif
    // Sales_data(istream &);

    //成员函数接口
    string isbn() const // const 是用来修饰this指针的，通过this指针无法修改成员，this默认类型是 Sales_data
                        // *const，添加了const之后，this类型变成从const Sales_data *const
    {
        return bookNo; // return this->bookNo
    }
    Sales_data &combine(const Sales_data &);

  private:
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    }
    //数据成员
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, Sales_data &);
istream &read(istream &, Sales_data &);

//定义成员函数
#if 0
Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}
#endif

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // this->units_sold += rhs.units_sold;
    revenue += rhs.revenue;       // this->revenue += rhs.revenue;
    return *this;                 //返回total的引用，total.combine().bookNo
}

//定义非成员函数

ostream &print(ostream &os, Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main(void)
{
    Sales_data item("book", 1, 1.1);
    print(cout, item);
    string null_book = "9-999-99999-9";

    //隐式类型转换只能允许一步类型转换成功，也就是入参和构造函数匹配；
    // item.combine(null_book); //参数为Sales_data, 但是传递的是字符串，通过构造函数构造了一个临时的对象；
    // item.combine(cin);

    //由于添加了explicit，只能使用直接初始化
    Sales_data item1(null_book);
    Sales_data item2{null_book};

    // Sales_data item3 = null_book; //错误：不能将explicit构造函数用于拷贝形式的初始化过程
    item.combine(Sales_data(null_book));
    // static_cast可以使用explicit构造函数进行转换
    item.combine(static_cast<Sales_data>(cin));
    return 0;
}
