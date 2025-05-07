#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>

using namespace std;

void print(const list<int> &ls)
{
    for (auto &s : ls)
        cout << s << " ";
    cout << endl;
}

void t_insert();
int main(void)
{
    t_insert();
    return 0;
}

void t_insert()
{
    list<int> lst{1, 2, 3, 4, 5};
    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    print(lst2);
    copy(lst.cbegin(), lst.cend(), back_inserter(lst3));
    print(lst3);
}

void t_istream()
{
    istream_iterator<int> int_is(cin); //将迭代器绑定到int的输入流
    istream_iterator<int> eof;
    ifstream in("afile");
    istream_iterator<string> str_it(in);

    vector<int> vec;
    istream_iterator<int> in_iter(cin);
    while (in_iter != eof)
        vec.push_back(*in_iter++);

    istream_iterator<int> in_iter(cin), eof;
    cout << accumulate(in_iter, eof, 0) << endl;
}

void t_ostream()
{
    vector<int> vec{1, 2, 3, 4, 5};
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec)
    {
        *out_iter++ = e;
        out_iter = e;
    }
    cout << endl;
}