#pragma once
#include <optional>
#include <string>

// typedef char bool;
// typedef char *string;

void *checked_malloc(int);

using std::string;
string String(char *);
string String_strip(char *, int);

/** simple linked list*/
template <typename T> struct List {
  struct Cons {
    T hd;
    List<T> *tl;
    Cons(T hd, List<T> *tl) : hd(hd), tl(tl) {}
  };

  std::optional<Cons> node;
  List() { node = {}; };
  List(std::optional<Cons> const &node) : node(node){};
  List(T hd, List<T> *tl) { node = Cons(hd, tl); }
  /** pushes a new element at the front of the list */
  static List<T> cons(T hd, List<T> *tl);
  /** head of the list */
  T head() { return node->hd; }
  /** tail of the list */
  List<T> *tail() { return node->tl; }
  /** is this the end of the list */
  bool is_nil() { return !node.has_value(); }

  /* is this copy ctor? */
  List(List const &) = default;
  /* list initialization 
   * @TODO make a contiguous list*/
  List(std::initializer_list<T> l) {
    node = {};
    for (auto it = std::rbegin(l); it < std::rend(l); it++) {
      node = Cons(*it, new List<T>(node));
    }
  }
};

template <typename T> inline List<T> List<T>::cons(T hd, List<T> *tl) {
  return List(hd, tl);
}
