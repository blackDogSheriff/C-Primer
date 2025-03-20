#include <iostream>
using namespace std;

void foreach_pointer(const int ia[][4], size_t rows);
void foreach_pointer_new(void);
void foreach_reference(void);
int main(void)
{
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    //指向数组的引用
    int(&r)[4] = ia[1];

    /* auto创建的row是一个指针，指向ia，因此col无法对指针进行遍历
    for (auto row:ia){
        for (auto col:row){
            cout << col << " ";
        }
        cout << endl;
    }
     */

    auto p1 = ia; // p的类型为 int (*p)[4]
    cout << (*p1)[0] << endl;

    return 0;
}

void foreach_reference(void)
{
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    for (auto &row : ia)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}

void foreach_pointer_new(void)
{
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    for (auto r = begin(ia); r != end(ia); ++r)
    {
        for (auto c = begin(*r); c != end(*r); ++c)
        {
            cout << *c << " ";
        }
        cout << endl;
    }
}

void foreach_pointer(const int ia[][4], size_t rows)
{
    for (auto r = ia; r != ia + rows; ++r)
    {
        for (auto c = *r; c != *r + 4; ++c)
        {
            cout << *c << " ";
        }
        cout << endl;
    }
}