#include <iostream>
#include <vector>
#include <utility>

using namespace std;
/*
- pair<T1, T2> p;
- pair<T1, T2> p{v1, v2};
- pair<T1, T2> p = {v1, v2};
- make_pair{v1, v2};

- p.first
- p.second
- p1 relop p2
 */

void t_pair();
pair<string, int> process(vector<string> &v);

int main(void)
{
    t_pair();
    return 0;
}

void t_pair()
{
    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<string>> p;

    pair<string, string> author{"James", "J.R.R.Tolkien"};
    cout << author.first << " " << author.second << endl;
}

pair<string, int> process(vector<string> &v)
{
    if (!v.empty())
    {
        return make_pair(v[0], v.size()); //自动推断类型
    }
    else
    {
        return pair<string, int>();
    }
}