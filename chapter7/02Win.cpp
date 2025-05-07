#include <iostream>
#include <vector>
using namespace std;
class Screen
{
    friend class Window_mgr;

  public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){};
    char get() const
    {
        return contents[cursor];
    }

    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

    void some_member() const;
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
    void do_display(ostream &os) const
    {

        int i = 0;
        for (auto &c : contents)
        {
            os << c;
            if (++i % width == 0)
            {
                os << "\n";
            }
        }
    }

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

void Screen::some_member() const
{
    ++access_ctr;
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline char Screen::get(pos ht, pos wd) const
{
    pos row = ht * width;
    return contents[row + wd];
}

class Window_mgr
{
  public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex); //清空指定的Screen

  private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

int main(void)
{
    Screen myScreen(5, 5, 'X');
    myScreen.display(cout);
    cout << endl;
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.set('*').display(cout);
}