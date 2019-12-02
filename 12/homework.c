#include"csapp.h"
/* 12.16
void *thread(void *vargp);

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	pthread_t tids[n];
	for(int i = 0; i < n; ++i) {
		pthread_create(&tids[i], NULL, thread, NULL);
	}

	pthread_exit(0);
}

void *thread(void *vargp) {
	printf("hello world    %d", pthread_self());
	return NULL;
}
*/


/*
 * 12.17
 *

void* thread(void *argp) {
	sleep(1);
	printf("hello\n");
	return NULL;
}

int main() {
	pthread_t tid;

	pthread_create(&tid, NULL, thread, NULL);
	pthread_exit(0);
}
the main thread exited, then kill all threads.
*/

/* 12.18
 * x v x
 */

/* 12.19
 * allow the waiting reader post readcnt.
 * .
 */

/* 12.20
 *
