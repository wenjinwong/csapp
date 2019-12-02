#include<stdlib.h>
#include<stdio.h>


int main() {
	void* p;
	p = malloc(15);
	printf("%p\n", p);
	p = malloc(4);
	printf("%p\n", p);
}
