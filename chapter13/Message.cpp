#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Message;

class Folder
{
  public:
    Folder() = default;
    Folder(const Folder &f) : msgs(f.msg)
    {
        add_to_Messages(f);
    }
    Folder &operator=(const Folder &);
    void addMsg(Message *m)
    {
        msgs.insert(m);
    }
    void remMsg(Message *m)
    {
        msgs.erase(m);
    }
    void add_to_Messages(const Folder &);
    void remove_from_Msgs();

    ~Folder()
    {
        remove_from_Msgs();
    }

  private:
    set<Message *> msgs;
};

Folder &Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
}
void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : f.msgs)
        msg->addFldr(this);
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}

void addFldr(Folder *f)
{
    folders.insert(f);
}
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

//电子邮件类
class Message
{
  public:
    Message(const string &str = "") : contents(str){};
    Message(const Message &);            //拷贝构造函数
    Message &operator=(const Message &); //拷贝赋值运算符
    ~Message();

    //从给定的Folder中添加删除本Message
    void save(Folder &);
    void remove(Folder &);

  private:
    string contents;       //消息文本
    set<Folder *> folders; //包含本Message的Folder

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void Message::add_to_Folders(const Message &)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();   //删除指向本地
    contents = rhs.contents; //赋值信息
    folders = rhs.folders;   //修改本地指向
    add_to_Folders(rhs);     //添加本地指向

    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::save(Folder &f)
{
    folders.insert(&f); // folders添加发送对象地址
    f.addMsg(this);     // folders保存message
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        r->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(rhs.contents, lhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

int main(void)
{
    return 0;
}
