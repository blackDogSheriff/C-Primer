#include <iostream>
using namespace std;
class Screen
{
  public:
    typedef string::size_type pos;

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

int main(void)
{
    return 0;
}