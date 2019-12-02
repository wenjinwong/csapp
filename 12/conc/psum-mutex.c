#include "csapp.h"
#define MAXTHREADS 32

void *sum_mutex(void *vargp);	/* Thread routine */

/* Global shared variables */
long gsum = 0;
long nelems_per_thread;
sem_t mutex;
long psum[MAXTHREADS];
int main(int argc, char **argv) {
	long i, nelems, log_nelems, nthreads, myid[MAXTHREADS];
	pthread_t tid[MAXTHREADS];

	/* Get input arguments */
	if(argc != 3) {
		printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
		exit(0);
	}
	nthreads = atoi(argv[1]);
	log_nelems = atoi(argv[2]);
	nelems = (1L << log_nelems);
	nelems_per_thread = nelems / nthreads;
	sem_init(&mutex, 0, 1);

	/* Create peer threads and wait for them to finish */
	for(i = 0; i < nthreads; ++i) {
		myid[i] = i;
		pthread_create(&tid[i], NULL, sum_mutex, &myid[i]);
	}
	for(i = 0; i < nthreads; ++i) 
		pthread_join(tid[i], NULL);

	/* Check final answer */
	if(gsum != (nelems * (nelems-1))/2)
		printf("Error: Actual=%d result=%ld\n", gsum, (nelems*(nelems-1))/2);
	exit(0);
}

void *sum_mutex(void *vargp) {
	long myid = *((long *)vargp);	/* Extract the thread ID */
	long start = myid * nelems_per_thread;
	long end = start + nelems_per_thread;
	long i;
	for(i = start; i < end; i++) {
		sem_wait(&mutex);
		gsum += i;
		sem_post(&mutex);
	}
	return NULL;
}


void *sum_array(void *vargp) {
	long myid = *((long *)vargp);
	long start = myid * nelems_per_thread;
	long end = start + nelems_per_thread;
	long i;
	
	for(i = start; i < end; i++) {
		psum[myid] += i;
	}
	return NULL;
}
