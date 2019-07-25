/*
 * util.c - commonly used utility functions.
 */

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *checked_malloc(int len) {
  void *p = malloc(len);
  if (!p) {
    fprintf(stderr, "\nRan out of memory!\n");
    exit(1);
  }
  return p;
}

string String(char *s) {
  string p = checked_malloc(strlen(s) + 1);
  strcpy(p, s);
  return p;
}
string String_strip(char *s, int size) {
  // size -2 quotes +1 \0-byte
  string p = checked_malloc(size-1);
  memcpy(p, s+1, size-1);
  p[size-2] = '\0';
  return p;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
  U_boolList list = checked_malloc(sizeof(*list));
  list->head = head;
  list->tail = tail;
  return list;
}
