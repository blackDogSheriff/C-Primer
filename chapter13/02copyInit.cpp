#include <iostream>
#include <vector>
using namespace std;
/*
- 什么时候会进行拷贝初始化？
    - 将一个对象作为实参传递给另一个非引用类型的形参时
    - 从一个返回类型为非引用类型的函数返回时
    - 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
    - 容器的insert、push等操作
- 直接初始化：
    - emplace
*/

int main(void)
{
    string dots(10, '.'); //直接初始化：调用构造函数

    //拷贝初始化：调用拷贝构造函数
    string s(dots);
    string s2 = s;
    string null_book = "9-9999-999999";
    string s3 = string(100, '9');
}

void t_explicit()
{
    vector<int> v1(10);
    /*
    - 首先，10要隐式类型转换成vector<int>类型，通过调用 vector<int>的构造函数来进行转换；
    - 但是vector<int>(size_n)构造函数是explicit的，不允许通过10进行转换，因此会失败
    */
    vector<int> v2 = 10;

    void f(vector<int>);
    f(10);              //错误，不能进行转换
    f(vector<int>(10)); //正确，直接初始化
}