#include <iostream>
#include <forward_list>
using namespace std;

void
test_and_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
    auto prev     = sflst.before_begin();
    auto curr     = sflst.begin();
    bool inserted = false;

    while (curr != sflst.end()) {
        if (*curr == s1)
            curr = sflst.insert_after(curr, s2);
        prev = curr;
        curr++;
    }
    if (!inserted)
        sflst.insert_after(prev, s2);
}

int
main(void)
{
    forward_list<int> lst;
    /*
        lst.before_begin();
        lst.cbefore_begin();

        lst.insert_after(p, t);
        lst.insert_after(p, n, t);
        lst.insert_after(p, b, e);
        lst.insert_after(p, il);

        lst.emplace_after(p, args);

        lst.erase_after(p);
        lst.erase_after(b, e);
    */

    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto              prev = flst.before_begin();
    auto              curr = flst.begin(); // 首元素
    while (curr != flst.end()) {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
    return 0;
}
