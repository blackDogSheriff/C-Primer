#include <iostream>
using namespace std;

int main(void)
{
    string line;
    while (getline(cin, line))
        if (!line.empty())
        {
            auto size = line.size();
            cout << line << ' ' << size << endl;
        }
}