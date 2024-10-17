#include <map>
#include <string>

int main()
{
  std::map<std::string, unsigned> word_count;

  std::map<std::string, unsigned>::const_iterator map_it = word_count.cbegin();
}