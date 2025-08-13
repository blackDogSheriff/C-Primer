#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
class StrBlobPtr; // 前向声明友类

class StrBlob
{
    friend class StrBlobPtr;

  public:
    typedef vector<string>::size_type size_type;

    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){};

    size_type size() const
    {
        return data->size();
    }

    bool empty() const
    {
        return data->empty();
    }

    void push_back(const string &s)
    {
        data->push_back(s);
    }
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

  private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string &msg) const;
};

inline void StrBlob::check(size_t i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

  public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){};
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){};

    string &deref() const;
    StrBlobPtr &incr();
    StrBlobPtr &decr();

  private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

inline string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr()
{
    if (curr == 0)
        throw out_of_range("decrement past begin of StrBlobPtr");
    --curr;
    return *this;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();

    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

#endif