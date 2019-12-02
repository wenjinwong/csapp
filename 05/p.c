#include<stdio.h>
int main() {
	int x = 1000, y = 3000;
	int qq, pp;
	int *q = &qq;
	*q = y;
	int *p = &pp;
	*p = x;
	int t1;
	t1 = *q;
	printf("%d", t1);
	return t1;
}
