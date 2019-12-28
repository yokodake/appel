/*
 * symbol.hpp - Symbols and symbol-tables
 *
 */
#pragma once
#include <map>

#include "util.hpp"
#include "table.hpp"

namespace tiger {
struct Symbol {
  constexpr static const unsigned int SIZE = 109;

  static std::map<std::string, Symbol *> hashtable;

  std::string name;

  /** Make a unique symbol from a given std::string.
   *  Different calls to symbol("foo") will yield the same Symbol
   *  value, even if the "foo" strings are at different locations. */
  static Symbol *symbol(std::string);

  template <typename T> struct Table {
    table::Table<Symbol, T> table;

    static const Symbol marksym;

    Table() : table(table::Table<Symbol, T>()) {}

    /** Enter a binding "sym->value" into table, shadowing but not deleting
     *    any previous binding of "sym". */
    void enter(Symbol *sym, T value);

    /** Look up the most recent binding of "sym" in table, or return NULL
     *    if sym is unbound. */
    std::optional<T> look(Symbol *sym);

    /** Start a new "scope" in table. Scopes are nested. */
    void beginScope();

    /** Remove any bindings entered since the current scope began,
     * and end the current scope. */
    void endScope();

    void dump(void (*show)(Symbol *sym, void *binding));
  };

private:
  Symbol() { name = ""; }
  Symbol(std::string n) : name(n) {}
};

template <typename T> const Symbol Symbol::Table<T>::marksym = Symbol("<mark>");

template <typename T>
inline void Symbol::Table<T>::enter(Symbol *sym, T value) {
  table.enter(sym, value);
}
template <typename T>
inline std::optional<T> Symbol::Table<T>::look(Symbol *sym) {
  return table.look(sym);
}

template <typename T> inline void Symbol::Table<T>::beginScope() {
  table.enter(const_cast<Symbol*>(&marksym), {});
}

template <typename T> inline void Symbol::Table<T>::endScope() {
  Symbols;
  do
    s = table.pop();
  while (s != &marksym);
}

template <typename T>
inline void Symbol::Table<T>::dump(void (*show)(Symbol *sym, void *binding)) {
  table.dump(show);
}
} // namespace tiger