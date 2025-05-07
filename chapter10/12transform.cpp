#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void t_transform();
void print_vector(const vector<int> &vec);
int main()
{

    t_transform();
    return 0;
}

void t_transform()
{
    vector<int> v1{-1, 2, -3, 4, 5};
    //目的位置和开始位置相同时，transform将输入序列中每个元素替换为可调用对象操作该元素得到的结果
    //只有一个return语句时，lambda表达式可以省略返回值类型
    transform(v1.begin(), v1.end(), v1.begin(), [](int i) { return i < 0 ? -i : i; });

    //必须指定返回值类型，否则会报错
    transform(v1.begin(), v1.end(), v1.begin(), [](int i) -> int {
        if (i < 0)
            return -i;
        else
            return i;
    });
    print_vector(v1);
}

void print_vector(const vector<int> &vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}