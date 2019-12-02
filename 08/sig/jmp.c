#include<setjmp.h>

int main() {
	int i;
	jmp_buf buf;
	i = setjmp(buf);
	printf("%d",i);
}
