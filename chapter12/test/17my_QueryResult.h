#ifndef MY_QUERY_RESULT_H
#define MY_QUERY_RESULT_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Str_Blob.h"
#include <set>

using namespace std;
class QueryResult
{
  public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;

    QueryResult(const string &s, shared_ptr<set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f){};
    set<line_no>::size_type size() const
    {
        return lines->size();
    }
    line_it begin() const
    {
        return lines->cbegin();
    }

    line_it end() const
    {
        return lines->cend();
    }

    StrBlob get_file() const
    {
        return file;
    }

  private:
    string sought;
    shared_ptr<set<line_no>> lines;
    StrBlob file;
};

#endif