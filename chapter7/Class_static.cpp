#include <iostream>
using namespace std;
class Account {
public:
    void calculate()
    {
        amount += amount * interestRate;
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double); // 公有静态成员函数
private:
    string owner;
    double amount = 0; // 一般来说不再类的内部初始化静态成员
    // 静态成员不属于对象，但是被所有对象共享
    static double interestRate;
    // 静态成员函数不和对象绑定，不包含this指针
    // 因此静态成员函数不可以声明成const成员函数，不能使用this指针//不能返回非静态变量？？？
    static double initRate(); // 静态成员函数 私有

    // 除了静态常量成员之外，其他静态成员不能在类的内部初始化
    static constexpr int period = 30;
    double               daily_tbl[period];
};

double
Account::initRate()
{
    return 1.231;
}

void
Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::interestRate = initRate();

int
main()
{
    double r;
    r = Account::rate();
#if 0
	Account ac1;
	Account *ac2 = &ac1;
	r = ac1.rate();
	r = ac2->rate();
#endif
    return 0;
}

/*
    1. 静态成员存在于对象之外，对象不含有静态成员
    2. 静态成员函数不能被声明成const，也不能在static函数内使用this指针；
*/
