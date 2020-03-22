#include "pch.h"
#include "../inc/util.hpp"

/** util.hpp **/
TEST(util_list, ctors) {
  using namespace tiger;
  auto l = list<int>();
  EXPECT_TRUE(l.is_nil());

  auto m = list<int>(l);
  EXPECT_TRUE(m.is_nil());

  l = list<int>(1);
  EXPECT_FALSE(l.is_nil());

  l = list<int>(1, m);
  EXPECT_FALSE(l.is_nil());
}  // namespace tests
TEST(util_list, headtest) {
  using namespace tiger;
  auto l = list<int>(1);
  EXPECT_EQ(1, l.head());
  EXPECT_EQ(1, head(l));
}
TEST(util_list, niltest) {
  using namespace tiger;
  auto l = list<int>();
  EXPECT_TRUE(l.is_nil());
  EXPECT_TRUE(is_nil(l));

  l = nil<int>();
  EXPECT_TRUE(l.is_nil());
}
TEST(util_list, tailtest) {
  using namespace tiger;
  auto l = list<int>(1, nil<int>());
  EXPECT_TRUE(l.tail().is_nil());

  l = cons(1, cons(2, nil<int>()));
  EXPECT_EQ(2, l.tail().head());
  EXPECT_TRUE(l.tail().tail().is_nil());
}
TEST(util_list, initialized_listtest) {
  using namespace tiger;
  auto l = list<int>{1, 2, 3};

  EXPECT_EQ(1, l.head());
  EXPECT_EQ(2, l.tail().head());
  EXPECT_EQ(3, l.tail().tail().head());
  EXPECT_TRUE(l.tail().tail().tail().is_nil());
}
TEST(util_list, iteratortest) {
  using namespace tiger;
  auto is = list<int>{1, 2, 3, 4};
  auto s = 0;
  for (auto i : is)
    s += i;
  EXPECT_EQ(10, s);
}
TEST(util_list, iterator2test) {
  using namespace tiger;
  auto xs = list<int>{1, 2, 3, 4};
  auto ys = nil<int>();
  for (auto x : xs)
    ys = cons(x, ys);
  EXPECT_EQ(xs.head(), ys.tail().tail().tail().head());
  EXPECT_EQ(xs.tail().head(), ys.tail().tail().head());
  EXPECT_EQ(xs.tail().tail().head(), ys.tail().head());
  EXPECT_EQ(xs.tail().tail().tail().head(), ys.head());
}
TEST(util_list, reversetest) {
  using namespace tiger;
  auto xs = list<int>{1, 2, 3, 4};
  auto ys = xs.reverse();
  EXPECT_EQ(xs.head(), ys.tail().tail().tail().head());
  EXPECT_EQ(xs.tail().head(), ys.tail().tail().head());
  EXPECT_EQ(xs.tail().tail().head(), ys.tail().head());
  EXPECT_EQ(xs.tail().tail().tail().head(), ys.head());
}
TEST(util_list, sizetest) {
  using namespace tiger;
  auto l = nil<int>();
  EXPECT_EQ((size_t)0, l.size());
  l = list<int>{1, 2};
  EXPECT_EQ((size_t)2, l.size());
  l = list<int>{1, 2, 3};
  EXPECT_EQ((size_t)3, l.size());
}
TEST(util_list, to_vec) {
  using namespace tiger;
  auto ls = (list<int>{1, 2, 3, 4}).to_vec();
  auto vs = std::vector<int>{1, 2, 3, 4};
  auto l = ls.begin();
  auto v = vs.begin();
  EXPECT_EQ(ls.size(), vs.size());
  for (; l != ls.end() || v != vs.end(); l++, v++)
    EXPECT_EQ(*l, *v);
}
TEST(util_list, assoc_folds) {
  using namespace tiger;
  auto ls = list<int>{1, 2, 3, 4};
  auto radd = [](int x, int acc) { return x + acc; };
  EXPECT_EQ(ls.foldr<int>(radd, 0),
            ls.foldl<int>(radd, 0));
}
