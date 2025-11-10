#include <iostream>
using namespace std;

class Sales_data
{
  public:
    //拷贝构造函数的参数必须是引用类型：
    // - 如果不是引用类型，那么构造的时候，将会调用拷贝构造函数，无限循环
    Sales_data() = default;
    Sales_data(const Sales_data &);
    Sales_data &operator=(const Sales_data &);
    ~Sales_data(){};

  private:
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

Sales_data::Sales_data(const Sales_data &ori) : bookNo(ori.bookNo), units_sold(ori.units_sold), revenue(ori.revenue){};
