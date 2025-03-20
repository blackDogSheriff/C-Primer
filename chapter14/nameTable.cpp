#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    /*
        vector<string *> nameTable;
        sort(nameTable.begin(), nameTable.end(),
            [](string *a, string *b) { return a < b; });
    */
    sort(nameTable.begin(), nameTable.end(), less<string *>());
    return 0;
}
