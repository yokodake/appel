#include <stdlib.h>
#include "util.h"

void *checked_malloc(int s) {
    void *p = malloc(s);
    assert(p);
    return p;
}
