#include <iostream>
using namespace std;

class SmallInt
{
  public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw out_of_range("Bad SmallInt value");
    }

    operator int() const
    {
        return val;
    }
    SmallInt &operator=(SmallInt &i)
    {
        val = i.val;
        return *this;
    }
    SmallInt &operator+(SmallInt &i)
    {
        *this = i;
        return *this;
    }
    int print() const
    {
        return val;
    }

  private:
    size_t val;
};
int main(void)
{
    SmallInt si; // 拷贝初始化
    SmallInt si1 = 3;
    cout << si.print() << endl;
    si = static_cast<SmallInt>(4);
    cout << si.print() << endl;
    si + si1;
    cout << si.print() << endl;
    return 0;
}
