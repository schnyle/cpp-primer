// Write your own versions of the shared_ptr and unique_ptr.

#include <cassert>
#include <iostream>

template <typename T> class unique_ptr
{
public:
  unique_ptr() = default;
  unique_ptr(T *ptr) : p(ptr) {}
  ~unique_ptr() { delete p; }

  unique_ptr(unique_ptr &&up) noexcept;
  unique_ptr &operator=(unique_ptr &&up) noexcept;

  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;

  T &operator*() const { return *p; }
  bool operator!() const { return p == nullptr; }

  T *get() const { return p; }
  T *release();
  void reset(T *new_p = nullptr);

private:
  T *p = nullptr;
};

template <typename T> unique_ptr<T>::unique_ptr(unique_ptr<T> &&up) noexcept
{
  p = up.get();
  up.p = nullptr;
}

template <typename T>
unique_ptr<T> &unique_ptr<T>::operator=(unique_ptr<T> &&up) noexcept
{
  if (this == &up)
  {
    return *this;
  }

  delete p;
  p = up.get();
  up.p = nullptr;

  return *this;
}

template <typename T> T *unique_ptr<T>::release()
{
  auto tmp = p;
  p = nullptr;
  return tmp;
}

template <typename T> void unique_ptr<T>::reset(T *new_p)
{
  delete p;
  p = new_p;
}

int main()
{
  std::cout << "basic construction and access\n";
  unique_ptr<int> ptr1(new int(42));
  assert(*ptr1 == 42);
  assert(ptr1.get() != nullptr);

  std::cout << "nullptr construction\n";
  unique_ptr<int> ptr2(nullptr);
  assert(ptr2.get() == nullptr);
  assert(!ptr2);

  std::cout << "move construction\n";
  unique_ptr<int> ptr3(new int(100));
  unique_ptr<int> ptr4 = std::move(ptr3);
  assert(*ptr4 == 100);
  assert(ptr3.get() == nullptr);

  std::cout << "move assignment\n";
  unique_ptr<int> ptr5(new int(200));
  unique_ptr<int> ptr6;
  ptr6 = std::move(ptr5);
  assert(*ptr6 == 200);
  assert(ptr5.get() == nullptr);

  std::cout << "release ownership\n";
  unique_ptr<int> ptr7(new int(300));
  int *raw = ptr7.release();
  assert(ptr7.get() == nullptr);
  assert(*raw == 300);

  std::cout << "reset\n";
  unique_ptr<int> ptr8(new int(400));
  ptr8.reset(new int(500));
  assert(*ptr8 == 500);
  ptr8.reset();
  assert(ptr8.get() == nullptr);

  std::cout << "copy does not compile\n";
  // unique_ptr<int> ptr10(new int(1));
  // unique_ptr<int> ptr11 = ptr10;
}