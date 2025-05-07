#include <iostream>
#include <vector>
#include <set>
#include <map>

/*
- map或者set中关键字必须是唯一的，但是multiset或者multimap中关键字可以重复
*/
using namespace std;

void t_multi()
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i < 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());

    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}
int main(void)
{
    t_multi();

    return 0;
}
