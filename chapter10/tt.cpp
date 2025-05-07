#include <iostream>
using namespace std;

class Book
{
  public:
    const Book &get(string name) const
    {
        do_get(name);
        return *this;
    }

    Book &get(string name)
    {
        do_get(name);
        return *this;
    }
    const Book &do_get(string name) const
    {
        return *this;
    }

    Book &set(string name)
    {
        this->name = name;
        return *this;
    }

  private:
    string name;
};

int main(void)
{
    Book book;
    book.get("C++ Primer").set("C++ Primer Plus");
    return 0;
}