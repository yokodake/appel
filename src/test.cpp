#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include "symbol.hpp"
#include "util.hpp"

struct foo {
  foo() { std::cout << "foo::ctor" << std::endl; }
  foo(const foo& other) { std::cout << "foo::copy" << std::endl; operator=(other); }
  ~foo() { std::cout << "foo:dtor" << std::endl; }
};

struct bar {
  std::variant<foo, std::vector<int>> _foo;
  bar(const foo& foo) : _foo(foo) { std::cout << "1" << std::endl; }
  bar(const std::vector<int>& foo) : _foo(foo) { std::cout << "1" << std::endl; }

  void test() { std::cout << ">" << std::get<std::vector<int>>(_foo).size() << std::endl;}
  static inline bar Bar(const foo& foo) { std::cout << "0" << std::endl; return bar(foo); }
};
void test(const foo& x) { std::cout << std::endl; }

int main() {
  using namespace tiger;

  auto ls = list{1, 2, 3};
  std::cout << "--" << std::endl;
  std::cout << "--" << std::endl;
  std::cout << ls.head() << std::endl;
  std::cout << ls.tail().head() << std::endl;
  std::cout << ls.tail().tail().head() << std::endl;
  std::cout << ls.tail().tail().tail().is_nil() << std::endl;
  std::cout << cons(1, cons(2, cons(3, nil<int>()))) << std::endl; 
  std::cout << list<int>(1, list<int>(2, list<int>(3, list<int>()))) << std::endl;
  std::cout << ls << std::endl;
  std::cout << ls.reverse() << std::endl;
  std::cout << ls.size() << std::endl;
  std::cout << "--" << std::endl;

  std::cout << "---" << std::endl; 
  bar _ = bar::Bar(foo());
  std::string s = "\"foo bar\"";
  size_t size = s.size();
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

  std::cout << "---" << std::endl;
  for (auto l : ls) {
    std::cout << l;
  }
  std::cout << std::endl << "--" << std::endl;

  return 0;
}
