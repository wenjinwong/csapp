#include<stdio.h>

int main() {
	float f = 1e125;
	int res = f / 1e-100;
	printf("%d\n", res);
	return 0;
}
