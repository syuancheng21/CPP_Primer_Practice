#include "ex13_34_36_37.h"

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::remove_from_folders() {
  for (auto f : this->folders) {
    f->remMsg(this);
  }
}

void Message::addFldr(Folder *f) { folders.insert(f); }

void Message::remFldr(Folder *f) { folders.erase(f); }

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  lhs.remove_from_folders();
  rhs.remove_from_folders();
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  lhs.add_to_folders(lhs);
  rhs.add_to_folders(rhs);
}

void Folder::addMsg(Message *m) { messsges.insert(m); }

void Folder::remMsg(Message *m) { messsges.erase(m); }

void Folder::add_to_messages(const Folder &f) {
  for (auto m : f.messsges) {
    m->addFldr(this);
  }
}

void Folder::remove_from_messages() {
  for (auto m : messsges) {
    m->remFldr(this);
  }
}

void swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  lhs.remove_from_messages();
  rhs.remove_from_messages();
  swap(lhs.messsges, rhs.messsges);
  lhs.add_to_messages(lhs);
  rhs.add_to_messages(rhs);
}