#include <iostream>
#include <array>

using namespace std;
int main(void)
{
    array<int, 42> ai;
    array<string, 10> as;
    //这里是要通过一个数组类型来创建它的size_type类型，一个完整的数组类型必须包含元素类型和元素个数
    array<int, 42>::size_type a_s;

    //拷贝初始化
    array<int, 5> ai2 = {1, 2, 3, 4, 5}; //列表初始化
    array<int, 5> ai3 = ai2;             //类型一致可以直接拷贝

    //赋值
    array<int, 5> ai4 = {1, 2, 3, 4, 5}; //列表初始化
    array<int, 5> ai5 = {0};             //所有元素都是0
    ai4 = ai5;                           //赋值，ai4的元素都变成0
    ai5 = {0}; //在C++11中是不允许的，必须类型相同才能赋值，右边类型可能和左边不匹配

    //swap
    array<int, 5> ai6 = {1, 2, 3, 4, 5}; //列表初始化
    array<int, 5> ai7 = {0};             //所有元素都是0
    ai6.swap(ai7);                       //交换ai6和ai7的元素
}