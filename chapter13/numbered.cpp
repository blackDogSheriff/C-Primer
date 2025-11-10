#include <iostream>
using namespace std;

class numbered
{
  public:
    numbered()
    {
        mysn = seq++;
    }
    numbered(numbered &n)
    {
        mysn = seq++;
    }
    int mysn;

  private:
    static int seq;
};

int numbered::seq = 0;

void f(const numbered &s)
{
    cout << s.mysn << endl;
}

int main(int argc, char **argv)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
