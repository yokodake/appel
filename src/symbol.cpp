#include "symbol.hpp"
#include "table.hpp"
#include "util.hpp"

namespace tiger {
Symbol::Symbol(std::string name) {
  auto r = hashtable.find(name);
  if (r != hashtable.end()) {
    s = r->second;
  } else {
    auto n = new Sym(name);
    hashtable[name] = n;
    s = n;
  }
}

std::map<std::string, Symbol::Sym *> Symbol::hashtable =
std::map<std::string, Symbol::Sym *>();
} // namespace Tiger