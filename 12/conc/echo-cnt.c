#include "csapp.h"

static int byte_cnt;	/* Byte counter */
static sem_t mutex;		/* and the mutex that protects it */

static void init_echo_cnt(void) {
	sem_init(&mutex, 0, 1);
	byte_cnt = 0;
}

void echo_cnt(int connfd) {
	int n;
	char buf[MAXLINE];
	rio_t rio;
	static pthread_once_t once = PTHREAD_ONCE_INIT;

	pthread_onece(&once, init_echo_cnt);
	rio_readinitb(&rio, connfd);
	while((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
		P(&mutex);
		byte_cnt += n;
		printf("server received %d (%d total) bytes on fd %d\n", n, byte_cnt, connfd);
		V(&mutex);
		rio_writen(connfd, buf, n);
	}
}

