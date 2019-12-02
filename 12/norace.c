#include"csapp.h"
#define N 4

void *thread(void *);

int main() {
	pthread_t tid[N];
	int i, *ptr;

	for(i = 0; i < N; i++) {
		ptr = (int*)malloc(sizeof(int));
		*ptr = i;
		
		pthread_create(&tid[i], NULL, thread, (void*)(i-5));
	}
	pthread_exit(0);
}

void *thread(void *argp) {
	int myid = ((int )argp);
	//free(argp);
	printf("Hello from thread %d\n", myid);
	return NULL;
}
