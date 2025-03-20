#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> s;
    s.push_back(string("ddjskla"));
    s.push_back(string("123123"));
    s.push_back(string("dog"));
    // 将第三个参数类型加到一起
    string sum = accumulate(s.cbegin(), s.cend(), string(""));

    cout << sum << endl;
    return 0;
}
