#include <iostream>
#include <list>
using namespace std;
int main(void)
{
    list<int> li = {1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = li.begin();
    while (iter != li.end())
    {
        cout << *iter << endl;
    }
}