#include <iostream>
#include <map>
#include <set>
#include <utility>
void add_child(map<string, vector<pair<string, string>>> &families, const string &family, const string &child,
               const string &birthday)
{
    families[family].push_back(make_pair(child, birthday));
}
int main(void)
{
    map<string, vector<pair<string, string>>> families;
    return 0;
}
