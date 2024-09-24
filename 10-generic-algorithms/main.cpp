#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<char *> v1{"hello", "there", "mother"};
  std::vector<char *> v2{"hello", "there", "mother"};

  auto res = std::equal(v1.cbegin(), v1.cend(), v2.cbegin());
  std::cout << "res: " << (res ? "true" : "false") << "\n";

  for (size_t i = 0; i < v1.size(); ++i)
  {
    std::cout << "v1[" << i << "] address: " << static_cast<void *>(v1[i]) << "\n";
    std::cout << "v2[" << i << "] address: " << static_cast<void *>(v2[i]) << "\n";
  }
}