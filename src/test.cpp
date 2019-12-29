#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include "symbol.hpp"
#include "util.hpp"


struct foo {};
using Foo = foo *;

int main() {
  using namespace tiger;

  auto _ = Foo();


  char* s = "\"foo bar\"";
  size_t size = strlen(s);
  auto a = Symbol("foo");
  auto b = Symbol("foo");
  std::cout << (a == b) << std::endl;

  auto t = Symbol::Table<int>();
  t.beginScope();
  t.enter(a, 3);
  std::cout << *t.look(a) << std::endl;
  t.endScope();
  std::cout << t.look(a).has_value() << std::endl;

  exit(1);
  std::cout << std::endl;

  auto ls = list{1, 2, 3};
  std::cout << ls.head() << std::endl;
  std::cout << ls.tail().head() << std::endl;
  std::cout << ls.tail().tail().head() << std::endl;
  std::cout << ls.tail().tail().tail().is_nil() << std::endl;
  std::cout << cons(1, cons(2, cons(3, nil<int>()))) << std::endl; 
  std::cout << list<int>(1, list<int>(2, list<int>(3, list<int>()))) << std::endl;
  std::cout << ls << std::endl;
  std::cout << ls.reverse() << std::endl;
  std::cout << ls.size() << std::endl;

  std::cout << "---" << std::endl;
  for (auto l : ls) {
    std::cout << l;
  }
  std::cout << std::endl << "--" << std::endl;

  return 0;
}