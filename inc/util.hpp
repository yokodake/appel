#pragma once
#include <memory>
#include <optional>
#include <string>
#include <iostream>

namespace tiger {

inline std::string String(char *s) { return std::string(s); }

inline std::string String_strip(char *s, int size) {
  return std::string(s + 1, s + size - 1);
}

/** simple linked list*/
template <typename T>
struct list {
  struct Cons;
  using _Cons = std::shared_ptr<Cons>;

  struct Cons {
    T hd;
    _Cons tl;
    Cons(T hd, _Cons tl) : hd(hd), tl(tl) {}
  };

  _Cons node;

  list() { node = nullptr; }

  list(list<T> const& ls) : node(ls.node) {}

  list(const T& hd)
    : node(std::make_shared<Cons>(hd, nullptr)) {}

  // inline list(T hd, list<T> tl) : node(std::make_shared<Cons>(hd, tl.node)) {}

  list(T hd, const list<T>& tl)
    : node(std::make_shared<Cons>(hd, tl.node)) {}

  list(const _Cons& node) : node(node) {}

  // list initialization
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

  bool is_nil() const { return node == nullptr; }

  // recursive process
  template <typename F, typename A>
  A foldr(F f, A z) const {
    if (is_nil())
      return z;
    else
      return f(head(), tail().foldr(f, z));
  }

  template <typename F, typename A>
  A foldl(F f, A z) const {
    for (auto it : *this)
      z = f(z, *it);
    return z;
  }

  // recursive process
  template <typename X, typename F>
  X map(F f){return list(f(head()), tail().map(f));}

  list<T> reverse() {
    list<T> rev = list();
    for (auto it : *this)
      rev = cons(it, rev);
    return rev;
  }

  size_t size() const {
    size_t s = 0;
    for (auto _ : *this)
      s++;
    return s;
  }

  class iterator {
    friend struct list;
    _Cons it;
    iterator(const _Cons& node) : it(node) {}

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

template<typename T>
static inline list<T> nil() {
  return list<T>();
}
// pass by value
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

}  // namespace tiger
