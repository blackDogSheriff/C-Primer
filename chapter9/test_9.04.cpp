#include <iostream>
#include <vector>
using namespace std;

bool is_contain(vector<int>::iterator b, vector<int>::iterator e, const int &val)
{
    while (b != e)
    {
        if (*b == val)
            return true;
        b++;
    }
    return false;
}

int main(void)
{
    vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //列表初始化
    cout << is_contain(iv.begin(), iv.end(), 11) << endl;
    cout << is_contain(iv.begin(), iv.end(), 7) << endl;
}