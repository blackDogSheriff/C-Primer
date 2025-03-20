#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int>::iterator it1;
    vector<int>::const_iterator it2; //既可以指向非常量对象，也可以指向常量对象

    const vector<int> v;
    const vector<int> cv;

    auto it3 = v.begin();  // vector<int>::iterator
    auto it4 = cv.begin(); // vector<int>::const_iterator
    auto it5 = v.cbegin(); // vector<int>::const_iterator

    return 0;
}

void mid_test(const string &text, const char sought)
{
    string::const_iterator begin = text.begin();
    string::const_iterator end = text.end();
    string::const_iterator mid = text.begin() + text.size() / 2;
    while (mid != end && *mid != sought)
    {
        if (*mid < sought)
        {
            end = mid;
        }

        if (*mid > sought)
        {
            begin = mid + 1;
        }

        mid = begin + (end - begin) / 2;
    }
    return;
}
