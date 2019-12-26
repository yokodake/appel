#include "symbol.hpp"
#include "table.hpp"
#include "util.hpp"

Symbol *Symbol::symbol(std::string name) {
  auto r = Symbol::hashtable.find(name);
  if (r != Symbol::hashtable.end())
    return r->second;
  Symbol *s = new Symbol(name);
  Symbol::hashtable[name] = s;
  return s;
}

std::map<std::string, Symbol *> Symbol::hashtable =
    std::map<std::string, Symbol *>();