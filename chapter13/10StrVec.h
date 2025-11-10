#ifndef __STR_VEC_H__
#define __STR_VEC_H__
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class StrVec
{
  public:
    StrVec(initializer_list<string> li);
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){};
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string &);
    size_t capacity() const
    {
        return cap - elements;
    }
    size_t size() const
    {
        return first_free - elements;
    }

    string *begin() const
    {
        return elements;
    }

    string *end() const
    {
        return first_free;
    }

    void reserve(size_t n)
    {
        if (n > capacity())
            reallocate(n);
    }

    void resize(size_t n);
    void resize(size_t n, const string &s);

  private:
    static allocator<string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void reallocate();
    void reallocate(size_t n);
    string *elements;
    string *first_free;
    string *cap;
};

StrVec::StrVec(initializer_list<string> li)
{
    auto newdata = alloc_n_copy(li.begin(), li.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s); //在共享内存中，构造一个对象，并++first_free指针
}

#endif // !__STR_VEC_H__

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for_each(elements, first_free, [](string &s) { alloc.destroy(&s); });
        // for (auto p = first_free; p != elements;)
        //     alloc.destroy(--p);                     //销毁对象
        alloc.deallocate(elements, cap - elements); //释放空间
    }
}

/*
拷贝构造函数：分配新的内存，拷贝源对象
*/
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

/*
- 移动构造函数：
    - 接管源对象
    - s是一个右值引用，本质上仍是一个具名变量，因此可以通过.访问成员，右值引用的特征是可以移动，而不是不能访问成员
    - 接管后源对象可以被销毁
-
*/
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //释放自身的内存
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

// void StrVec::reallocate()
//{
//     //如果存在元素，分配 2 * size()，如果没有元素，分配1个元素空间
//     auto newcapacity = size() ? 2 * size() : 1;
//     auto newdata = alloc.allocate(newcapacity);
//
//     auto dest = newdata;
//     auto elem = elements; //旧数据
//
//     for (size_t i = 0; i != size(); ++i)
//         /*
//         调用move返回的结果会令construct使用string的移动构造函数，由于我们使用了移动构造函数，string管理的内存不会被拷贝
//         构造的每个string，都会从element指向的string那里接管内存的所有权
//         */
//         alloc.construct(dest++, std::move(*elem++)); // move:将左值转换成右值的引用，启动移动语义
//     free();                                          //释放当前空间
//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    /*
    - uninitialized_copy: 使用拷贝构造函数
    - make_move_iterator函数将一个普通迭代器转换为一个移动迭代器
        - 因此调用的移动构造函数，来构造每一个string
    */
    auto last =
        uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first); //将对象移动到新的空间
    free();                                                                                //释放旧的空间
    elements = first;
    first_free = last;
}

void StrVec::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t n)
{
    if (n > size())
    {
        while (size() < n)
            push_back("");
    }
    else if (n < size())
    {
        while (size() > n)
            alloc.destroy(--first_free);
    }
}

void StrVec::resize(size_t n, const string &s)
{
    if (n > size())
    {
        while (size() < n)
        {
            push_back(s);
        }
    }
}
