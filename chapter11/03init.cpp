#include <iostream>
#include <set>
#include <map>

using namespace std;
int main(void)
{
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "and", "or", "an", "a", "the", "of"};
    map<string, string> authors = {
        {"James", "J.R.R.Tolkien"}, {"J.R.R.Tolkien", "J.K.Rowling"}, {"J.K.Rowling", "George R.R.Martin"}};

    return 0;
}