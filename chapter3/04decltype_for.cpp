#include <iostream>
using namespace std;

void decltype_test(const string &s);
int main(void)
{
    string s = {"fjdkslfjds"};
    decltype_test(s);
    return 0;
}

void decltype_test(const string &s)
{
    string tmp_s = s; //拷贝初始化
    for (decltype(tmp_s.size()) index = 0; index != tmp_s.size(); ++index)
    {
        tmp_s[index] = toupper(tmp_s[index]);
        cout << tmp_s << endl;
    }
}