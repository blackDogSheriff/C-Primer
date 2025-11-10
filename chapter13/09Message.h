#include <iostream>
#include <09Folder.h>

using namespace std;

class Message
{
    friend void swap(Message &lhs, Message &rhs);
    friend class Folder;
    explicit Message(const string &str = "") : contents(str){};

    Message(const Message &);
    Message &operator=(const Message &);

    Message(Message &&m) noexcept;
    Message &operator=(Message &&) noexcept;
    ~Message();

    void save(Folder &);
    void remove(Folder &);
    void addFldr(Folder *);

  public:
  private:
    string contents;                      //消息内容
    set<Folder *> folders;                // message所在的文件夹
    void add_to_Folders(const Message &); //将本message，添加到m所在的folders中
    void remove_from_Folders();           //从所有Folder中删除Message
    void move_Folders(Message *m);
};

Message::Message(Message &&m) noexcept : contents(move(m.contents))
{
    move_Folders(&m);
}

Message &Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        //先清理自身
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}
void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear(); //确保m销毁是无害的
}

void Message::save(Folder &f)
{
    folders.insert(&f); //添加的是指针
    f.addMsg(this);     //将自身添加到folders
}

void Message::remove(Folder &f)
{
    folders.erase(&f); //删除指针
    f.remMsg(this);    //将自身从folders删除
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); //将本消息添加到m指向的folders中
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &m)
{
    //避免自己给自己复制
    remove_from_Folders(); //清理已经有的Folder
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Message::addFldr(Folder *f)
{
    folders.insert(f);
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto msg : f.msgs)
        msg->addFldr(this);
}

void Folder::remove_from_Msgs(const Folder &f)
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}