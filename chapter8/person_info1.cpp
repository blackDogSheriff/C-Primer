#include <iostream>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(void)
{
    string line, word;
    vector<PersonInfo> prople;
    istringstream record(line);
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : perple)
    {
        ostringstream formatted, badNums;
    }
    return 0;
}
