#include "symbol.hpp"
#include "util.hpp"
#include <iostream>
#include <iterator>
#include <string>

int main() {
  char *s = "\"foo bar\"";
  size_t size = strlen(s);
  auto a = Symbol::symbol("foo");
  auto b = Symbol::symbol("foo");
  std::cout << (a == b) << std::endl;

  auto t = Symbol::Table<int>();
  t.beginScope();
  t.enter(a, 3);
  std::cout << *t.look(a) << std::endl;
  return 0;
}