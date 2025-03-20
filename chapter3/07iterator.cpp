#include <iostream>
#include <string>
#include <vector>

using namespace std;

void iterator_test(string &s);
void calc_grade(void);
int main(void)
{
    string s("some string");
    iterator_test(s);
    return 0;
}

void iterator_test(string &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (isalpha(*it))
        {
            *it = toupper(*it);
        }
    }
}

void calc_grade(void)
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }
}