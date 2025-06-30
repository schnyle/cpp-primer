// Write your own versions of the shared_ptr and unique_ptr.

#include <cassert>
#include <iostream>

template <typename T> class shared_ptr
{
public:
  shared_ptr() = default;
  shared_ptr(T *ptr) : p(ptr), n_refs(new unsigned(1)) {}
  ~shared_ptr();

  shared_ptr(shared_ptr &&sp) noexcept;
  shared_ptr &operator=(shared_ptr &&sp) noexcept;

  shared_ptr(const shared_ptr &);
  shared_ptr &operator=(const shared_ptr &);

  T &operator*() const { return *p; }
  bool operator!() const { return p == nullptr; }

  unsigned refs() const { return n_refs ? *n_refs : 0; }
  T *get() const { return p; }
  void reset(T *new_p = nullptr);

private:
  T *p = nullptr;
  unsigned *n_refs = nullptr;
};

template <typename T> shared_ptr<T>::~shared_ptr()
{
  if (n_refs == nullptr)
  {
    return;
  }

  --*n_refs;
  if (*n_refs == 0)
  {
    delete n_refs;
    delete p;
  }
}

template <typename T> shared_ptr<T>::shared_ptr(const shared_ptr &sp)
{
  p = sp.p;
  n_refs = sp.n_refs;
  if (n_refs != nullptr)
  {
    ++*n_refs;
  }
}

template <typename T>
shared_ptr<T> &shared_ptr<T>::operator=(const shared_ptr &sp)
{
  if (this == &sp)
  {
    return *this;
  }

  if (sp.n_refs != nullptr)
  {
    ++*sp.n_refs;
  }

  if (n_refs != nullptr && --*n_refs == 0)
  {
    delete n_refs;
    delete p;
  }

  n_refs = sp.n_refs;
  p = sp.p;
  return *this;
}

template <typename T> shared_ptr<T>::shared_ptr(shared_ptr &&sp) noexcept
{
  n_refs = sp.n_refs;
  p = sp.p;

  sp.p = nullptr;
  sp.n_refs = nullptr;
}

template <typename T>
shared_ptr<T> &shared_ptr<T>::operator=(shared_ptr &&sp) noexcept
{
  if (n_refs != nullptr)
  {
    --*n_refs;
    if (*n_refs == 0)
    {
      delete n_refs;
      delete p;
    }
  }

  n_refs = sp.n_refs;
  p = sp.p;

  sp.p = nullptr;
  sp.n_refs = nullptr;

  return *this;
}

template <typename T> void shared_ptr<T>::reset(T *new_p)
{
  if (n_refs != nullptr)
  {
    --*n_refs;

    if (*n_refs == 0)
    {
      delete n_refs;
      delete p;
    }
  }

  n_refs = new_p ? new unsigned(1) : nullptr;
  p = new_p;
}

int main()
{
  std::cout << "Basic construction and access\n";
  shared_ptr<int> ptr1(new int(42));
  assert(*ptr1 == 42);
  assert(ptr1.get() != nullptr);
  assert(ptr1.refs() == 1);

  std::cout << "Copy construction (shares ownership)\n";
  shared_ptr<int> ptr2 = ptr1;
  assert(*ptr2 == 42);
  assert(ptr1.refs() == 2);
  assert(ptr2.refs() == 2);
  assert(ptr1.get() == ptr2.get()); // same object

  std::cout << "Copy assignment\n";
  shared_ptr<int> ptr3;
  ptr3 = ptr1;
  assert(ptr1.refs() == 3);
  assert(ptr3.refs() == 3);

  std::cout << "Modification through one affects all\n";
  *ptr2 = 100;
  assert(*ptr1 == 100);
  assert(*ptr3 == 100);

  std::cout << "Destroying one decreases count\n";
  {
    shared_ptr<int> ptr4 = ptr1;
    assert(ptr1.refs() == 4);
  }
  assert(ptr1.refs() == 3); // ptr4 destroyed

  std::cout << "Reset decreases count\n";
  ptr2.reset();
  assert(ptr1.refs() == 2);
  assert(ptr2.get() == nullptr);
  assert(ptr2.refs() == 0);

  std::cout << "Reset with new object\n";
  ptr2.reset(new int(200));
  assert(*ptr2 == 200);
  assert(ptr2.refs() == 1);

  std::cout << "Move construction (transfers ownership efficiently)\n";
  shared_ptr<int> ptr5 = std::move(ptr1);
  assert(*ptr5 == 100);
  assert(ptr5.refs() == 2);      // ptr3 still exists
  assert(ptr1.get() == nullptr); // moved from

  std::cout << "Move assignment\n";
  shared_ptr<int> ptr6;
  ptr6 = std::move(ptr3);
  assert(ptr6.refs() == 2); // ptr5 still exists
  assert(ptr3.get() == nullptr);

  std::cout << "Last owner cleanup\n";
  ptr5.reset();
  ptr6.reset(); // object should be deleted here
}