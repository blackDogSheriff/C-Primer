#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

void add_family(map<string, vector<string>> &families, const string &family)
{
    if (families.find(family) == families.end())
    {
        families[family] = vector<string>(); //没有找到则新建
    }
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child)
{
    families[family].push_back(child);
}

void print_families(const map<string, vector<string>> &families)
{
    for (auto const &family : families)
    {
        for (auto const &child : family.second)
        {
            cout << family.first << " " << child << ", ";
        }
        cout << endl;
    }
}

int main()
{
    map<string, vector<string>> families;
    add_family(families, "Smith");
    add_child(families, "Smith", "John");
    add_child(families, "Smith", "Jane");

    add_family(families, "Doe");
    add_child(families, "Doe", "Alice");
    add_child(families, "Doe", "Bob");

    print_families(families);

    return 0;
}
