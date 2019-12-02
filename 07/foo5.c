#include<stdio.h>
void f(void);

int y = 0x10;
int x = 0x10;

int main() {
	f();
	printf("x = 0x%x y = 0x%x\n", x, y);
	return 0;
}


