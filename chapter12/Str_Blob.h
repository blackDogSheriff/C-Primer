#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr; // 友类声明

class StrBlob
{
    friend class StrBlobPtr;

  public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    // 添加和删除元素
    void push_back(const string &t)
    {
        data->push_back(t);
    }
    void pop_back();
    // 元素访问
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

  private:
    shared_ptr<vector<string>> data;
    // 如果data[i]不合法，抛出一个异常
    void check(size_type i, const string &msg) const;
};

// 构造函数定义
inline StrBlob::StrBlob() : data(make_shared<vector<string>>())
{
}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il))
{
}

// 判断第i个元素是否存在
inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
inline const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
inline string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
inline const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

//=========================================================================================//
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &); // 判断俩指针指向是否想等
  public:
    StrBlobPtr() : curr(0)
    {
    }
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)
    {
    }
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)
    {
    }

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
    auto ret = wptr.lock(); // 判断vector是否存在
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

// 返回当前元素
inline string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

// 将curr+1
inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// 将curr-1
inline StrBlobPtr &StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
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
