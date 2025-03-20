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
    while (getline(cin, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    return 0;
}
