#include <iostream>
#include <string>
using namespace std;

int main()
{
}
void t_create_arr()
{
    /*
        - 不能对动态数组使用begin或者end
        - 不能使用范围for
    */
    int *p1 = new int[10]; //创建十个int的数组
    int *p2 = new int(42); //创建一个int的对象

    typedef int arrT[10];
    int *p3 = new arrT; //创建一个int的数组

    int *p4 = new int[10](); //值初始化为0
    string *p5 = new string[10]();

    /*
    - 列表初始化元素个数超过大小：new失败，不会分配任何内存
    */
    int *p6 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string *p7 = new string[10]{"hello", "world", "!", string(10, 'a')};

    int *p8 = new int[0]; //不可以创建大小为0的数组，但是不会报错，不能解引用
}

void t_delete_arr()
{
    int *p1 = new int[10];
    delete[] p1;
}