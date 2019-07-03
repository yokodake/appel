#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* string;
string String(char *);

typedef char bool;
#define FALSE 0;
#define TRUE 1;

void *checked_malloc(int);
