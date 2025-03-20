#include <iostream>
#include <list>
#include <queue>
using namespace std;
int main(void)
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odd_d, even_d;

    for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
        if (*iter & 1)
            odd_d.push_back(*iter);
        else
            even_d.push_back(*iter);
    cout << "奇数有：";
#if 0
	for (auto iter = odd_d.cbegin(); iter != odd_d.cend(); iter++)
		cout << *iter << " ";
#endif
    for (auto i : odd_d)
        cout << i << " ";
    cout << endl;
    cout << "偶数有：";
    for (auto i : even_d)
        cout << i << " ";
    cout << endl;
    return 0;
}
