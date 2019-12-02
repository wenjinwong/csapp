/* WARNING THIS CODE IS BUGGY! */
#include<semaphore.h>
#include "csapp.h"

void *thread(void *vargp);	/* thread routine prototype */

/* Global shared varible */
volatile long cnt = 0;	/* Counter */
sem_t mutex;			/* Semapthore that protects counter */

int main(int argc, char **argv) {
	sem_init(&mutex, 0, 1);	/* mutex = 1 */

	long niters;
	pthread_t tid1, tid2;

	/* Check input arguments */
	if(argc != 2) {
		printf("usage: %s <niters>\n", argv[0]);
		exit(0);
	}
	niters = atoi(argv[1]);

	/* Create threads and wait for them to finish */
	pthread_create(&tid1, NULL, thread, &niters);
	pthread_create(&tid2, NULL, thread, &niters);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	/* Check result */
	if(cnt != (2 * niters))
		printf("BOOM! cnt = %ld\n", cnt);
	exit(0);
}

/* Thread routine */
void *thread(void *vargp) {
	long i, niters = *((long *)vargp);

	for(i = 0; i < niters; i++){
		sem_wait(&mutex);
		cnt++;
		sem_post(&mutex);
	}
	return NULL;
}
