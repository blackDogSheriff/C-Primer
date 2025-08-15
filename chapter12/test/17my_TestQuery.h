#ifndef MY_TEST_QUERY_H
#define MY_TEST_QUERY_H
#include <iostream>
#include <string>
#include "17my_QueryResult.h"

using namespace std;
class QueryResult;
class TestQuery
{
  public:
    using line_no = vector<string>::size_type;
    TestQuery(ifstream &);
    QueryResult query(const string &) const;
    void display_map();

  private:
    StrBlob file;
    map<string, shared_ptr<set<QueryResult::line_no>>> wm;
};

TestQuery::TestQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file.push_back(text);
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            word = cleanup_str(word);
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<QueryResult::line_no>);
        }
    }
}

#endif