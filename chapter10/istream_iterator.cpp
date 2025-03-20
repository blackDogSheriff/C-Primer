#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main(void)
{
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;
    ifstream in("afile");
    istream_iterator<string> str_it(in);

    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    while (in_iter != eof)
        vec.push_back(*in_iter++);

    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof); // 使用范围迭代器构造vec

    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
    return 0;
}
