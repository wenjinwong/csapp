#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

int *matvec(int **A, int *x, int n) {
	int i, j;
	int *y = (int *) malloc(n *sizeof(int));

	for(i = 0; i != n; i++) {
		for(j = 0 ; j < n; j++) {
			A[i] += A[i][j] * x[j];
		}
	}
	return y;
}

int main() {
	int *y = (int*)malloc(4);
	printf("%d", *y);
}
