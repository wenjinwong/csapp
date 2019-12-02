#include<stdio.h>
static int x = 0x1;
void f() {
	x = 0x1;
	printf("%d\n", x);
}
