#include <iostream>
#include <vector>
using namespace std;
int
main(void)
{
    vector<int> ilist1;
    vector<int> ilist2(ilist1);                   // 类型必须相同
    vector<int> ilist2 = ilist1;                  // 等价
    vector<int> ilist  = {1, 2, 3.0, 4, 5, 6, 7}; // 列表初始化
    vector<int> ilist3{1, 2, 3.0, 4, 5, 6, 7};    // 等价
    vector<int> ilist4(ilist.begin() + 2,
                       ilist.end() - 1); // 范围拷贝,只需要元素类型相同
    vector<int> ilist5(7);
    vector<int> ilist6(7, 3);
}
