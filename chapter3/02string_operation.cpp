#include <iostream>
#include <cstring>
using namespace std;
void get_input();
void print(const string &);
int main(void)
{
    char str[] = "fjdkls";
    cout << strlen(str) << endl;
    cout << sizeof(str) << endl;

    get_input();
}

void get_input()
{
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
            break;
        auto size = s.size();
        cout << s << ' ' << size << endl;
    }
}

void print(const string &s)
{
    cout << s << endl;
}