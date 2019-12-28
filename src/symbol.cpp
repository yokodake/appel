#include "symbol.hpp"
#include "table.hpp"
#include "util.hpp"

namespace tiger {
Symbol *Symbol::symbol(std::string name) {
  auto r = Symbol::hashtable.find(name);
  if (r != Symbol::hashtable.end())
    return r->second;
  auto s = new Symbol(name);
  Symbol::hashtable[name] = s;
  return s;
}

std::map<std::string, Symbol *> Symbol::hashtable =
    std::map<std::string, Symbol *>();
} // namespace Tiger