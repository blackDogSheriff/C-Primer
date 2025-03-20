#include <iostream>
using namespace std;

int main(void)
{
    string s1;          // 默认初始化，s1是一个空串
    string s2(s1);      //直接初始化
    string s21 = s1;     //拷贝初始化
    string s3 = "hiya"; //拷贝初始化
    string s4(10, 'a'); //拷贝初始化
}