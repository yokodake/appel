/*
 * util.cpp - commonly used utility functions.
 */
#include "util.hpp"

namespace tiger {
std::string String(char *s) { return std::string(s); }
string String_strip(char *s, int size) {
  return std::string(s + 1, s + size - 1);
}
} // namespace tiger