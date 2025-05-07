#include <iostream>
using namespace std;
class Account
{
  public:
    void calculate()
    {
        //成员直接访问静态成员
        amount += amount * interestRate;
    }

    static double rate()
    {
        return interestRate;
    };

    static void rate(double);

  private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

    static constexpr int period = 30; //字面值常量类型的值，在类内初始化
    double daily_tbl[period];
};

constexpr int Account::period;

double Account::initRate()
{
    interestRate = 0.0;
    return interestRate;
}

//外部定义静态成员时，不能重复添加static关键字
void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::interestRate = initRate();

int main(void)
{
    double r = Account::rate(); //使用作用域运算符访问静态成员
    cout << r << endl;

    Account acl;
    Account *acl2 = &acl;

    acl.rate();
    acl2->rate();
}