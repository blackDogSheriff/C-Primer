#include "01Bulk_quote.h"
#include "01Quote.h"

using namespace std;

void print_total(ostream &os, const Quote &item, size_t n)
{
    // 根据传入的对象类型调用相应版本的net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // 调用Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
}

int main(void)
{
    Quote base;
    // Bulk_Quote *bulkP = &base;  //错误：不能将基类转换成派生类
    // Bulk_Quote &bulkRef = base; //错误：不能将基类转换成

    Bulk_Quote bulk;
    Quote *itemP = &bulk; // 派生类对象的地址可以赋给基类指针
}

void t_dynamic_bind()
{
    Quote base("100-100-100", 50);
    Bulk_Quote bulk("200-200-200", 50, 10, 0.2);

    print_total(cout, base, 5);  // 调用Quote::net_price
    print_total(cout, bulk, 15); // 调用Bulk_Quote::net_price

    base = bulk;        // 使用Quote的赋值运算符
    base.net_price(15); // 调用Quote::net_price
}