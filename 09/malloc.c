#include<stdlib.h>
#include<stdio.h>


int main() {
	char *pa, *pb, *pc;
	pa = (char*)malloc(8);
	pb = (char*)malloc(16);
	pc = (char*)malloc(32);
	printf("%p	%p	%p\n", pa, pb, pc);
	free(pb);
	char *pd, *pe;
	pd = (char*)malloc(24);
	pe = (char*)malloc(1);
	printf("%p  %p\n", pd, pe);
	return 0;
}
