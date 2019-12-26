/*
 * util.c - commonly used utility functions.
 */

#include "util.hpp"

std::string String(char *s) {
  return std::string(s);
}
string String_strip(char *s, int size) {
  return std::string(s+1, s + size -1);
}
