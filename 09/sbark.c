#include<stdio.h>
#include<unistd.h>


int main() {
	void *p;
	p = sbrk(16);
	char *pc = (char*)p;
	for(int i = 0; i < 10; i++)
		*(pc + i) = 'i';
	printf("%p  %s\n", p, p);
	return 0;
}
