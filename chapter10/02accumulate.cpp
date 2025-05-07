#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> s;
    s.push_back(string("ddjskla"));
    s.push_back(string("123123"));
    s.push_back(string("dog"));
    // 将第三个参数类型加到一起
    string sum = accumulate(s.cbegin(), s.cend(), string("result:"));

    cout << sum << endl;
    return 0;
}
void t_equal()
{
    string s1 = "123";
    string s2 = "234";
    equal(s1.cbegin(), s1.cend(), s2.cbegin()); //第二个序列只有一个迭代器，因此该算法假定第二个序列至少和第一个一样长
}
