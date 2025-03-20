#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    deque<string> sd;
    string word;
    while (cin >> word)
        sd.push_back(word);
    for (auto si = sd.cbegin(); si != sd.cend(); si++)
        cout << *si << endl;

    return 0;
}
