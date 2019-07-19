#include <stdio.h>

struct foo { int a; int b; };
int i = 1;

struct foo bar(int x) {
	struct foo foo;
	foo.a = x+i;
	foo.b = ++i;
	return foo;
}

void main() {
	struct foo x = bar(2);
	struct foo y = bar(5);
	printf("%d-%d\n", x.a, x.b);
	printf("%d-%d\n", y.a, y.b);
}
