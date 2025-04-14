#include <iostream>
using namespace std;
/*
- 类静态成员存在于任何对象之外；无论创建多少对象，静态成员只有一个，且被所有的对象共享
- 静态成员不和任何对象绑定在一起，不包含this指针；
- 静态成员不能声明成const的，不能再static函数中使用this指针；
 */

class Accout
{
  public:
    void calculate()
    {
        //成员函数可以直接访问静态成员，不需要加上Accout::
        amount += amount * interestRate;
    }

    //静态成员函数不包含this指针，只能访问静态成员
    //静态成员函数不能声明成const的，应为和this指针无关
    static double rate()
    {
        return interestRate;
    }

    static double print_p()
    {
        return period;
    }

    static void rate(double);

  private:
    /*
    - 静态成员不属于类，因此不是在创建对象的时候进行定义的，也不是由构造函数进行初始化的；
    - 一般来说不能在类的内部初始化静态成员；
    - 必须在类的外部定义和初始化每个静态成员
    */
    string owner;
    double amount;
    static double interestRate; //静态成员只声明，在类外定义；
    static double initRate(); // 私有成员函数

    //通常情况下类静态成员不应该在类的内部进行初始化，但是可以提供const整数类型的类内初始值，前提是静态成员变量必须是字面值常量类型的constexpr
    static constexpr int period = 30; //常量表达式
    double daily_tbl[period];         //如果没有在外面定义，则外面无法访问period
};

//不需要重复添加static
void Accout::rate(double newRate)
{
    //静态成员函数可以直接访问静态成员
    interestRate = newRate;
}

double Accout::initRate()
{
    interestRate = 0.0;
    return interestRate;
}

//静态数据成员定义在任何函数之外，一旦定义就一直存在于程序的整个生命周期中
double Accout::interestRate = initRate(); //虽然initRate是私有的，也可以用来初始化interestRate
//常量静态成员在类内进行初始化了，通常情况下在类的外部也要重新定义一下该成员
constexpr int Accout::period;              //不需要再指定另一个初始值

int main(void)
{

    double r;
    r = Accout::rate();

    int a = Accout::print_p();

    cout << a << endl;

    //虽然静态成员不属于类对象，但是仍然可以使用类对象、引用、指针来访问静态成员
    Accout ac1;
    Accout *ac2 = &ac1;
    ac1.rate();
    ac2->rate();

    //类成员的初始化
    return 0;
}

/*
- 静态成员可以是不完全类型
- 静态成员的类型可以是它所属的类类型，非静态成员只能声明成它所属的类的指针或者引用
- 可以使用静态成员作为实参，非静态的成员不能作为实参，因为它的值本身属于对象的一部分，这么做的结果是无法真正提供一个对象
*/

/*
- 静态成员不能是const原因：
    - const必须在定义时初始化，静态成员不允许直接初始化 
    - 静态成员必须在类外单独定义（需要分配存储空间）
*/