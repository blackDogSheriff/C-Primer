#include <iostream>
#include <deque>
using namespace std;
int main(void)
{
    deque<string> sd;
    string word;
    deque<string>::iterator it = sd.begin();
    while (cin >> word)
    {
        // sd.push_back(word);
        it = sd.insert(it, word);
    }

    for (auto be = sd.begin(), en = sd.end(); be != en; ++be)
    {
        cout << *be << endl;
    }
}