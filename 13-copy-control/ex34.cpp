// 34. Write the Message class as described in this section.

// 36. Design and implement the corresponding Folder class. That class should
// hold a set that points to the Messages in that folder.

#include <iostream>
#include <set>
#include <string>
#include <vector>

class Message;
class Folder;

class Folder
{
public:
  Folder() = delete;
  Folder(const std::string &s) : name(s) {}

  void addMsg(Message *m) { messages.insert(m); }
  void remMsg(Message *m) { messages.erase(m); }

  void print() const;

private:
  std::string name;
  std::set<Message *> messages;
};

class Message
{
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  void save_to_Folder(Folder &);
  void remove_from_Folder(Folder &);

  std::string get_contents() const { return contents; }
  void set_contents(const std::string &s) { contents = s; }

private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
  add_to_Folders(m);
};

Message &Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message::~Message() { remove_from_Folders(); };

void Message::save_to_Folder(Folder &f)
{
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove_from_Folder(Folder &f)
{
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
  for (auto *f : m.folders)
  {
    f->addMsg(this);
  }
};

void Message::remove_from_Folders()
{
  for (auto *f : folders)
  {
    f->remMsg(this);
  }
};

inline void swap(Message &lhs, Message &rhs)
{
  using std::swap;

  for (auto *f : lhs.folders)
  {
    f->remMsg(&lhs);
  }
  for (auto *f : rhs.folders)
  {
    f->remMsg(&rhs);
  }

  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);

  for (auto *f : lhs.folders)
  {
    f->addMsg(&lhs);
  }
  for (auto *f : rhs.folders)
  {
    f->addMsg(&rhs);
  }
}

void Folder::print() const
{
  std::cout << name << ":\n";
  for (const auto m : messages)
  {
    std::cout << "\t" << m->contents << "\n";
  }
}

int main()
{
  Folder inbox("inbox");
  Folder spam_Folder("spam");
  Folder work_Folder("work");

  Message new_job("You got hired.");
  new_job.save_to_Folder(inbox);
  new_job.save_to_Folder(work_Folder);

  Message new_job_copy = new_job;
  new_job_copy.set_contents(new_job_copy.get_contents() + " (copy)");

  Message dad("Buy new clothes you slob.");
  dad.save_to_Folder(inbox);

  Message credit_one("Get a new credit card.");
  credit_one.save_to_Folder(inbox);
  credit_one.save_to_Folder(spam_Folder);

  credit_one = dad;

  std::vector<Folder *> folders{&inbox, &spam_Folder, &work_Folder};
  for (const auto f : folders)
  {
    f->print();
  }
}