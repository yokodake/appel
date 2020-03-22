#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char *string;
typedef struct table_ *table;
struct table_ {string id; int value; table tail;};
table Table(string id, int value, table tail) {
    table t = malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->tail = tail;
    return t;
}
table tb = NULL;
int lookup(table t, string id) {
    assert(t != NULL);
    if (id == t->id)
       return t->value;
    else
      return lookup(t->tail, id);
}
void update(table *t, string id, int value) {
     *t = Table(id, value, *t);
}

void main(void) {
    update(&tb, "foo", 1);
    table t = tb;
    while(t != NULL) {
        printf("%s: %d\n", t->id, t->value);
        t = t->tail;
    }
    update(&tb, "bar", 2);
    t = tb;
    while(t != NULL) {
        printf("%s: %d\n", t->id, t->value);
        t = t->tail;
    }
}
