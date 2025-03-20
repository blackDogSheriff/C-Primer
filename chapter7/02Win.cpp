#include <iostream>
#include <vector>
using namespace std;
/*
成员函数返回某个属性，则不需要返回*this
 */

class Screen
{
    //将Window_mgr作为Screen的友元，则Screen的所有友元对Window_mgr都可见
    friend class Window_mgr;
    // 只将Window_mgr::clear设置为友元，Window_mgr::clear必须在Screen类之前被声明
    // friend Window_mgr &Window_mgr::clear(ScreenIndex);

  public:
    typedef string::size_type pos;
    // using pos  = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c){};

    char get() const //隐式内联，定义在类内部的成员函数都是隐式内联的
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const; //显示内联
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &clear();
    pos get_pos() const
    {
        return cursor;
    }

    void some_member() const;

    /*
    如果要返回 对象本身的引用（*this），那么就需要定义两个版本的接口：
        - 一个为const版本，用来返回const对象的引用
        - 一个为非const版本，用来返回非const对象的引用
    以便后续继续调用其他接口

    */
    Screen &display(ostream &os)
    { // this的类型为 Screen *const
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    { // this的类型为 const Screen *const
        do_display(os);
        return *this;
    }

    pos size() const
    {
        return height * width;
    }

    void dummy_fcn(pos height)
    {
        cursor = width * height; //入参
        //下面三个使用的是类中的height
        cursor = width * this->height; //
        cursor = width * Screen::height;
        // cursor = width * ::height;
    }

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr; //可变数据成员，永远不会是const的，即便是对象是const

    void do_display(ostream &os) const
    {
        os << contents;
    }
};

class Window_mgr
{
  public:
    using ScreenIndex = vector<Screen>::size_type;
    Window_mgr &clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);

  private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

Window_mgr &Window_mgr::clear(ScreenIndex i)
{
    // screens[i].clear();
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
    return *this;
}

Screen &Screen::clear()
{
    contents = string(height * width, ' ');
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

//在外部定义内联
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

//已经在内部定义内联
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const
{
    ++access_ctr;
}

int main(void)
{
    Screen s(10, 10, 'X');
    cout << s.get_pos() << " " << s.get() << endl;
    s.move(5, 5);
    cout << s.get_pos() << " " << s.get() << endl;

    Screen myScreen(5, 3, '/');
    const Screen blank(5, 3, 's');

    myScreen.set('#').display(cout).set('s');
    blank.display(cout);

    return 0;
}