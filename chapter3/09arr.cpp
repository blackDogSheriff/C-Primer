#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string nums[] = {"one", "two", "three"};

    string *p = &nums[0];
    string *p1 = nums; //两者等价

    /*
     * auto对数组：指向数组第一个元素的指针
     */
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia);     // int *，指向ia的第一个元素
    auto ia3(&ia[0]); //两者等价

    /* decltype：返回类型为数组 */
    decltype(ia) ia4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia4是一个包含十个int的数据

    int *beg = begin(ia); //获取指向数组首个元素的指针
    int *last = end(ia);  //获取指向数组尾元素下一个的指针，方便匹配迭代器写法

    while (beg != last && *beg >= 0)
    {
        ++beg;
    }

    // use arr init vector
    vector<int> ivec(begin(ia), end(ia));
    cout << ivec.size() << endl;

    return 0;
}