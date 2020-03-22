#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

namespace tiger {

inline std::string String(char* s) { return std::string(s); }

inline std::string String_strip(char* s, int size) {
  return std::string(s + 1, s + size - 1);
}

/** simple linked list*/
template <typename T>
struct list {
  struct Cons;
  using _Cons = std::shared_ptr<Cons>;

  /* inner rep. */
  struct Cons {
    T hd;
    _Cons tl;
    Cons(T hd, _Cons tl)
        : hd(hd)
        , tl(tl) {}
  };

  _Cons node;

  /* API */
  list() { node = nullptr; }

  list(list<T> const& ls)
      : node(ls.node) {}

  list(const T& hd)
      : node(std::make_shared<Cons>(hd, nullptr)) {}

  list(T hd, const list<T>& tl)
      : node(std::make_shared<Cons>(hd, tl.node)) {}

  list(const _Cons& node)
      : node(node) {}

  // list initialization, O(n), iterative process
  // @TODO make a contiguous list?
  list(std::initializer_list<T> l) {
    node = nullptr;
    std::cout << *std::rbegin(l) << std::endl;
    for (auto it = std::rbegin(l); it < std::rend(l); it++) {
      node = std::make_shared<Cons>(*it, node);
    }
  }

  // head of the list
  T head() const {
    if (is_nil())
      std::runtime_error("list is nil");
    else
      return node->hd;
  }

  // tail of the list
  list<T> tail() const {
    if (is_nil())
      std::runtime_error("list is nil");
    else
      return list(node->tl);
  }

  // O(1)
  bool is_nil() const { return node == nullptr; }

  // recursive process
  template <typename Z, typename F>
  // Z foldr(std::function<Z(T, Z)> f, Z z) const { // @FIXME
  Z foldr(F f, Z z) const {
    if (is_nil())
      return z;
    else
      return f(head(), tail().foldr(f, z));
  }

  // iterative process
  template <typename Z, typename F>
  // Z foldl(std::function<Z(Z, T)> f, Z z) const { // @FIXME
  Z foldl(F f, Z z) const {
    for (auto it : *this)
      z = f(z, it);
    return z;
  }

  // recursive process
  template <typename U, typename F>
  U map(F f) {
    return list(f(head()), tail().map(f));
  }
  // iterative process
  list<T> reverse() const {
    list<T> rev = list();
    for (auto it : *this)
      rev = cons(it, rev);
    return rev;
  }
  // O(n), iterative process
  size_t size() const {
    size_t s = 0;
    for (auto _ : *this)
      s++;
    return s;
  }
  // O(n), iterative process
  std::vector<T> to_vec() const {
    return foldl(
        [](std::vector<T> vs, T x) {
          vs.push_back(x);
          return vs;
        },
        std::vector<T>());
  }

  /* iterators */
  class iterator {
    friend struct list;
    _Cons it;
    iterator(const _Cons& node)
        : it(node) {}

  public:
    T operator*() const { return it->hd; }
    iterator& operator++() {
      it = it->tl;
      return *this;
    }
    bool operator!=(const iterator& o) { return o.it != it; }
  };

  iterator begin() const { return iterator(node); }
  iterator end() const { return iterator(nullptr); }
};

/* static functions */

template <typename T>
static inline list<T> nil() {
  return list<T>();
}
template <typename T>
static inline list<T> cons(const T& hd, const list<T>& tl) {
  return list<T>(hd, tl);
}
template <typename T>
static inline bool is_nil(const list<T>& ls) {
  return ls.is_nil();
}
template <typename T>
static inline T head(const list<T>& ls) {
  return ls.head();
}
template <typename T>
static inline list<T> tail(const list<T>& ls) {
  return ls.tail();
}

/* operator overloading */
template <typename T>
std::ostream& operator<<(std::ostream& os, const list<T>& xs) {
  bool b = true;
  os << "{";
  for (auto x : xs) {
    if (b)
      b = false;
    else
      os << ",";
    os << x;
  }
  os << "}";
  return os;
}

} // namespace tiger
