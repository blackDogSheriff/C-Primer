#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

string make_plural(int count, const string &s, const string &s1)
{
    if (count > 0)
        return s + s1;
    else
        return s;
}

inline void output_words(const vector<string> &words)
{
    for (auto &a : words)
        cout << a << " ";
    cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);
    auto bc = count_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    cout << bc << " " << make_plural(bc, "word", "s") << " of length " << sz << " or longer" << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);
    biggies(words, 6);
    return 0;
}
