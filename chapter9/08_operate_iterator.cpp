#include <iostream>
#include <vector>
using namespace std;
void print_vector(vector<int> &v);
void t_operate_iterator();
int main(void)
{
    t_operate_iterator();
    return 0;
}
void t_operate_iterator()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto iter = v.begin();
    while (iter != v.end())
    {
        if (*iter % 2)
        {
            iter = v.insert(iter, *iter); //删除当前元素，并返回下一个元素
            iter += 2;
        }
        else
        {
            iter = v.erase(iter); //删除当前元素，并返回下一个元素
        }
    }

    print_vector(v);
}

void print_vector(vector<int> &v)
{
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}