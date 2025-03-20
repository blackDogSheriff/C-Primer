#include <iostream>
using namespace std;
class StrBlob
{
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
};
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data != rhs.data;
}

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

  public:
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr &operator++(int);
    StrBlobPtr &operator--(int);
    string &operator*() const
    {
        auto p = check(curr, "dereference past endl");
        return (*p)[curr];
    }
    string *operator->() const
    {
        return &this->operator*();
    }
};

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

//相等运算符应该将工作委托给另外一个，意味着其中一个运算符应该负责实际的比较对象的工作
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

int main(void)
{
    //显示调用后++
    StrBlobPtr p(a1);
    p.operator++(0); //前置
    p.operator++();  //后置
    return 0;
}
