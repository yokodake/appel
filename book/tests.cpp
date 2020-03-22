#include "../inc/util.hpp"
#include "CppUnitTest.h"
#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests {
using namespace tiger;
TEST_CLASS(listTests){public :

                          TEST_METHOD(ctors){auto l = list<int>();
Assert::IsTrue(l.is_nil());

auto m = list<int>(l);
Assert::IsTrue(m.is_nil());

l = list<int>(1);
Assert::IsFalse(l.is_nil());

l = list<int>(1, m);
Assert::IsFalse(l.is_nil());
}  // namespace tests
TEST_METHOD(headtest) {
  auto l = list<int>(1);
  Assert::AreEqual(1, l.head());
  Assert::AreEqual(1, head(l));
}
TEST_METHOD(niltest) {
  auto l = list<int>();
  Assert::IsTrue(l.is_nil());
  Assert::IsTrue(is_nil(l));

  l = nil<int>();
  Assert::IsTrue(l.is_nil());
}
TEST_METHOD(tailtest) {
  auto l = list<int>(1, nil<int>());
  Assert::IsTrue(l.tail().is_nil());

  l = cons(1, cons(2, nil<int>()));
  Assert::AreEqual(2, l.tail().head());
  Assert::IsTrue(l.tail().tail().is_nil());
}
TEST_METHOD(initialized_listtest) {
  auto l = list<int>{1, 2, 3};

  Assert::AreEqual(1, l.head());
  Assert::AreEqual(2, l.tail().head());
  Assert::AreEqual(3, l.tail().tail().head());
  Assert::IsTrue(l.tail().tail().tail().is_nil());
}
TEST_METHOD(iteratortest) {
  auto is = list<int>{1, 2, 3, 4};
  auto s = 0;
  for (auto i : is)
    s += i;
  Assert::AreEqual(10, s);
}
TEST_METHOD(iterator2test) {
  auto xs = list<int>{1, 2, 3};
  auto ys = nil<int>();
  for (auto x : xs)
    ys = cons(x, ys);
  Assert::AreEqual(xs.head(), ys.tail().tail().tail().head());
  Assert::AreEqual(xs.tail().head(), ys.tail().tail().head());
  Assert::AreEqual(xs.tail().tail().head(), ys.tail().head());
  Assert::AreEqual(xs.tail().tail().tail().head(), ys.head());
}
TEST_METHOD(sizetest) {
  auto l = nil<int>();
  Assert::AreEqual((size_t)0, l.size());
  l = list<int>{1, 2};
  Assert::AreEqual((size_t)2, l.size());
  l = list<int>{1, 2, 3};
  Assert::AreEqual((size_t)3, l.size());
}
TEST_METHODE(to_vec) {
  auto ls = list<int>{1, 2, 3, 4};
  auto vs = std::vector<int>{1, 2, 3, 4};
  auto l = ls.begin();
  auto v = vs.begin();
  Assert::AreEqual(ls.size(), vs.size());
  for (; l != ls.end() || v != vs.end(); l++, v++)
    Assert::AreEqual(*l, *v);
}
}
;
}
