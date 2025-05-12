#include <iostream>
#include <memory>
#include <vector>
#include "04StrBlobPtr.h"

using namespace std;
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

  public:
    typedef vector<string>::size_type size_type;
    StrBlob() = default;
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){};
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }

    void push_back(const string &t)
    {
        data->push_back(t);
    }

    void pop_back();

    string &front();
    string &front() const;
    string &back();
    string &back() const;
    StrBlobPtr begin()
    {
        return StrBlobPtr(*this);
    }

    StrBlobPtr end()
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    };

  private:
    shared_ptr<vector<string>> data;
    // 判断给定索引是否合理，如果不合理则抛出异常
    void check(size_t i, const string &msg) const;
};

void StrBlob::check(size_t i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}