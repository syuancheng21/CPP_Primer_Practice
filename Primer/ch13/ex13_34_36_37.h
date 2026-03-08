#ifndef SYUAN_EX13_34_36_37_H
#define SYUAN_EX13_34_36_37_H

#include <set>
#include <string>

class Folder;

class Message {
  friend void swap(Message &lhs, Message &rhs);
  friend class Folder;

public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_folders(m);
  }
  Message &operator=(const Message &rhs) {
    contents = rhs.contents;
    remove_from_folders();
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
  }

  ~Message() { remove_from_folders(); }
  // explicit Message(const Message &) {} // disable copy constructor

  void save(Folder &);

  void remove(Folder &);

private:
  std::string contents;       //信息内容
  std::set<Folder *> folders; //本信息所有所在的文件夹

  void add_to_folders(const Message &);

  void remove_from_folders();

  void addFldr(Folder *);

  void remFldr(Folder *);
};

void swap(Message &lhs, Message &rhs);

class Folder {
  friend void swap(Folder &lhs, Folder &rhs);
  friend class Message;

public:
  Folder() = default;
  Folder(const Folder &f) : messsges(f.messsges) { add_to_messages(f); }
  Folder &operator=(const Folder &rhs) {
    remove_from_messages();
    messsges = rhs.messsges;
    add_to_messages(rhs);
    return *this;
  }
  ~Folder() { remove_from_messages(); }

private:
  std::set<Message *> messsges;

  void add_to_messages(const Folder &);

  void remove_from_messages();

  void addMsg(Message *m);

  void remMsg(Message *m);
};

void swap(Folder &lhs, Folder &rhs);

#endif // SYUAN_EX13_34_36_37_H
