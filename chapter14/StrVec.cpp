#include <iostream>

using namespace std;

class StrVec
{
  public:
    string &operator[](size_t n)
    {
        return elements[n];
    }
    const string &operator[](size_t n) const
    {
        return elements[n];
    }

  private:
};

int main(void)
{
    return 0;
}
