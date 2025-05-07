#include <iostream>
#include <map>

using namespace std;

void t_map();
int main(void)
{
    t_map();
    return 0;
}
void t_map()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
}
