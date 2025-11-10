#include <iostream>
using namespace std;
class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    StrVec(const StrVec &);            //拷贝构造
    StrVec &operator=(const StrVec &); //拷贝赋值
    ~StrVec();
    void push_back(const string &); //拷贝元素
    size_t size() const
    {
        return first_free - elements;
    }
    size_t capacity() const
    {
        return cap - elements;
    }
    string *begin() const
    {
        return elements;
    }
    string *end() const
    {
        return first_free;
    }

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

    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destory(--p);
    }
}

int main(void)
{
    return 0;
}
