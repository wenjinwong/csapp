#include<stdio.h>

int main() {
	int i;
	int *y, *x;
	for( i = 0; i < 100; ++i) {
		*y = i;
		*x = i + 1;
	}
	*x = *y = i;
}

