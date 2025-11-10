#ifndef _FOLDER_H
#define _FOLDER_H

#include <iostream>
#include <set>
using namespace std;

class Message;
class Folder
{
  public:
    Folder() = default;
    Folder(const Folder &f) : msgs(f.msgs){};

    Folder &operator=(const Folder &);
    void addMsg(Message *m)
    {
        msgs.insert(m);
    }

    void remMsg(Message *m)
    {
        msgs.erase(m);
    }

    void add_to_Message(const Folder &); //让folder中所有的msg也引用自己
    void remove_from_Msgs(const Folder &);

  private:
    set<Message *> msgs;
};

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Message(f);
}

Folder &Folder::operator=(const Folder &f)
{
    remove_from_Msgs(f);
    msgs = f.msgs;
    add_to_Message(f);
    return *this;
}

#endif