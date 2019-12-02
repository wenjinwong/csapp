#include<stdio.h>

int main() {
	int *p;
	int i = 4;
	int *pp = &i;
	p = pp;
	printf("%d", (*p));
}
