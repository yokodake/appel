/*
 * table.hpp - generic hash table
 *
 * No algorithm should use these functions directly, because
 *  programming with void* is too error-prone.  Instead,
 *  each module should make "wrapper" functions that take
 *  well-typed arguments and call the TAB_ functions.
 */
#pragma once
#include <cassert>

namespace tab {

template <typename K, typename T> struct Table {
  struct Binder {
    K *key;
    T value;
    Binder *next;
    K *prevtop;

    Binder(K *key, T value, Binder *next, K* prevtop)
        : key(key), value(value), next(next), prevtop(prevtop) {}
  };

  static constexpr const unsigned int TABSIZE = 127;

  Binder *tab[TABSIZE];
  K *top;

  /** Make a new table mapping "keys" to "values" */
  Table() {
    top = nullptr;
    for (int i = 0; i < TABSIZE; i++)
      tab[i] = nullptr;
  }
  /** Enter the mapping "key"->"value" into table,
   * shadowing but not destroying any previous binding for "key". */
  void enter(K *key, T value);
  /** Look up the most recent binding for "key" in table */
  std::optional<T> look(K *key);
  /** Pop the most recent binding and return its key.
   * This may expose another binding for the same key, if there was one. */
  K *pop();
  /** Call "show" on every "key"->"value" pair in the table,
   * including shadowed bindings, in order from the most
   * recent binding of any key to the oldest binding in the table */
  void dump(void (*show)(K *key, T value));
};

/* The cast from pointer to integer in the expression
 *   ((unsigned)key) % TABSIZE
 * may lead to a warning message.  However, the code is safe,
 * and will still operate correctly.  This line is just hashing
 * a pointer value into an integer value, and no matter how the
 * conversion is done, as long as it is done consistently, a
 * reasonable and repeatable index into the table will result.
 */
template <typename K, typename T>
inline void Table<K, T>::enter(K *key, T value) {
  int i = ((unsigned int) key) % TABSIZE;
  tab[i] = new Binder(key, value, tab[i], top);
  top = key;
}
template <typename K, typename T> inline std::optional<T> Table<K, T>::look(K *key) {
  int i = ((unsigned)key) % TABSIZE;
  for (auto b = tab[i]; b; b = b->next)
    if (b->key == key)
      return b->value;
  return {};
}
template <typename K, typename T> K *Table<K, T>::pop() {
  auto k = top;
  assert(k);
  int i = ((unsigned)k) % TABSIZE;
  auto b = tab[i];
  assert(b);
  tab[i] = b->next;
  top = b->prevtop;
  return b->key;
}
template <typename K, typename T>
void Table<K, T>::dump(void (*show)(K *key, T value)) {
  auto k = top;
  int i = ((unsigned)k) % TABSIZE;
  auto b = tab[index];
  if (b == NULL)
    return;
  tab[i] = b->next;
  top = b->prevtop;
  show(b->key, b->value);
  this->dump(show);
  assert(top == b->prevtop && tab[i] == b->next);
  top = k;
  tab[i] = b;
}
} // namespace tab