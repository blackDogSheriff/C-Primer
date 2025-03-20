#include <iostream>
using namespace std;
class ReadString {
public:
    ReadString(istream &is = cin)
        : is(is)
    {
    }
    string operator()()
    {
        string line;
        if (!getline(is, line)) {
            line = " ";
        }
        return line;
    }

private:
    istream &is;
};

void
testReadString()
{
    ReadString     rs;
    vector<string> vec;
    while (1) {
        string line = rs();
        if (!line.empty())
            vec.push_back(line);
        else
            breake;
    }
}

private:
int
main(void)
{
    return 0;
}
