/*
 * symbol.hpp - Symbols and symbol-tables
 *
 */
#pragma once
#include <map>

#include "table.hpp"

namespace tiger {
struct Symbol {
private:
  struct Sym {
    std::string name;

    Sym()
        : name("") {}
    Sym(std::string n)
        : name(n) {}
  };
  Sym* s;

public:
  constexpr static const unsigned int SIZE = 109;

  static std::map<std::string, Sym*> hashtable;

  template <typename T>
  struct Table {
    table::Table<Sym, T> table;

    static const Sym marksym;

    Table()
        : table(table::Table<Sym, T>()) {}

    /** Enter a binding "sym->value" into table, shadowing but not deleting
     *    any previous binding of "sym". */
    void enter(Symbol sym, T value) { table.enter(sym.s, value); }

    /** Look up the most recent binding of "sym" in table, or return NULL
     *    if sym is unbound. */
    std::optional<T> look(Symbol sym) { return table.look(sym.s); }

    /** Start a new "scope" in table. Scopes are nested. */
    void beginScope() { table.enter(const_cast<Sym*>(&marksym), {}); }

    /** Remove any bindings entered since the current scope began,
     * and end the current scope. */
    void endScope() {
      Sym* s;
      do
        s = table.pop();
      while (s != &marksym);
    }

    template <typename PF>
    void dump(PF show) {
      table.dump(show);
    }
  };

  /** Make a unique symbol from a given std::string.
   *  Different calls to symbol("foo") will yield the same Sym
   *  value, even if the "foo" strings are at different locations. */
  Symbol(std::string s);

  friend bool operator==(const Symbol& x, const Symbol& y) {
    return x.s == y.s;
  }
  std::string name();
};

template <typename T>
const Symbol::Sym Symbol::Table<T>::marksym = Symbol::Sym("<mark>");

} // namespace tiger