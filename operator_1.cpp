#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <map>

struct StrSym {
 public:

 bool operator<(const StrSym& other) const { return strcmp(str_, other.str_) < 0; }
 bool operator==(const StrSym& other) const { return strcmp(str_, other.str_) == 0; }

 const char* str() const { return str_; }

 private:
  friend const StrSym operator"" _sym(const char* str, std::size_t);

  StrSym(const char* str) : str_(str) {}
  const char* str_;
};

const StrSym operator"" _sym(const char* str, std::size_t) { return StrSym(str); }

int main(void)
{
    std::map<StrSym, int> map;
    map["0"_sym] = 1;
    map["1"_sym] = 2;
    map["3"_sym] = 3;
}