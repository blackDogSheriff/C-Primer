#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    //默认初始化
    vector<int> v1;

    //直接初始化
    // vector<int> v8 = 10; //错误，必须使用直接初始化来指定元素的数量

    //拷贝初始化
    vector<int> v2(v1);
    vector<int> v3 = v1;

    //值初始化，构造对象
    vector<int> v4(3, 10); // 3个10
    vector<int> v5(3);     // 3个0

    //列表初始化
    vector<int> v6 = {1, 2, 3, 4, 5, 6};
    vector<int> v7{1, 2, 3, 4, 5, 6};

    //想要列表初始化，值花括号中的必须和vector对象值类型一致
    vector<int> v9{3, 10};      // 3个0
    vector<int> v10{3};         //一个3
    vector<string> v11{"hiya"}; //一个hiya
    vector<string> v12{3};      // 3个默认初始化元素
}

void trans_test(void)
{
    string hexdigits = "0123456789ABCDEF";
    string result;
    string::size_type n;
    // decltype(s.size()) n;
    while (cin >> n)
    {
        if (n < 0 || n > 15)
        {
            result += hexdigits[n];
        }
    }
}