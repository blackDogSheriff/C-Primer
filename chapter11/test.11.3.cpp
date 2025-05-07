#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void t_read_file(char *p_file);

string &trans1(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main(int argc, char *argv[])
{
    t_read_file(argv[1]);
}

void t_read_file(char *p_file)
{
    ifstream in(p_file);
    if (!in)
    {
        cout << "open file failed" << endl;
        exit(1);
    }

    map<string, size_t> word_count;
    string word;
    while (in >> word)
    {
        ++word_count[word];
    }

    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
}
