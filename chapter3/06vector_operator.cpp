#include <iostream>
#include <vector>
using namespace std;

void init_vector(vector<int> &v1);
void vector_opt_test(void);
void foreach_vector(const vector<int> &v1);

int main(void)
{
    vector_opt_test();
}

void vector_opt_test(void)
{
    vector<int> v1;
    init_vector(v1);
    foreach_vector(v1);
}

void init_vector(vector<int> &v1)
{
    for (int i = 0; i < 100; ++i)
    {
        v1.push_back(i);
    }
}

void foreach_vector(const vector<int> &v1)
{
    if (!v1.empty())
    {
        for (auto &i : v1)
        {
            cout << i << endl;
        }
    }

    vector<int>::size_type s1 = v1.size();
    decltype(v1.size()) s2 = v1.size();
    cout << "size: " << s1 << endl;
}
