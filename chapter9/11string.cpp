#include <iostream>
using namespace std;

void t_string();
void t_insert();
void print_string(string &s);
int main(void)
{
    t_string();
    t_insert();
}

void t_string()
{
    const char *str = "hello world";

    string s1(str, 5);
    string s11(str, 6, 20); //只拷贝到末尾
    string s12(str, 20);    //报错
    print_string(s1);

    string s("hello world");

    string s2(s, 6);
    print_string(s2);

    string s3(s, 6, 3);
    print_string(s3);

    const char cr[] = {'1', '2', '3', '4', '5'};
    string s4(cr, 2);
    string s5(cr); //未定义：不是空字符串结束
    print_string(s4);
}

void t_substr()
{
    string s("hello world");

    string s1 = s.substr(6);
    string s2 = s.substr(6, 3);
    string s3 = s.substr(12);    // oor
    string s4 = s.substr(6, 12); //只会拷贝到\n
}

void t_insert()
{
    string s("hello world");
    s.insert(s.size(), 5, '!');
    s.erase(s.size() - 5, 2); //删除后5个字符
    print_string(s);

    const char *str = "hello world";
    s.assign(str, 7);
    print_string(s);

    s.insert(s.size(), str + 7);
    print_string(s);

    string s1 = "some string", s2 = "some other string";
    s1.insert(0, s2, 0, s2.size());
    print_string(s1);
}

void t_append()
{
    string s("C++ Primer"), s2 = s;
    s.insert(s.size(), " 4th Edition");
    s2.append(" 4th Edition");

    s.replace(11, 3, "5th");
    //等价
    //s.erase(11, 3);
    //s.insert(11, "5th");


}

void t_search() {

}

void t_compare() {

}

void print_string(string &s)
{
    cout << s << endl;
}