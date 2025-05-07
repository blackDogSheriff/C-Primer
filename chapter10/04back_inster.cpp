#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void print_vector(const vector<int> &v);

int main(void)
{
    vector<int> i;

    //返回一个迭代器，通过该迭代器赋值时，会调用push_back将一个具有给定值的元素添加到容器中；
    auto it = back_inserter(i);

    *it = 42;
    *it = 2;
    *it = 5; //赋值：直接在尾后push_back

    print_vector(i);

    fill_n(back_inserter(i), 10, 3); //在尾后添加十个3
    print_vector(i);
}

void print_vector(const vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}