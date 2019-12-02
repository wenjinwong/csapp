#include<pthread.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct buf{
	int queue[10];
	int front;
	int rear;
	pthread_mutex_t mutex;
	void* (*get)(void *);
	void* (*put)(void *);
}queue;

struct buf *q;
void * get(void * w) {
	pthread_mutex_lock(&q->mutex);
	int val = q->queue[q->front];
	q->front = (q->front+1)%10;
	pthread_mutex_unlock(&q->mutex);
	return (void*)(&val);
}

void* put( void *val) {
	pthread_mutex_lock(&q->mutex);
	q->queue[q->rear++] = *(int*)val;
	pthread_mutex_unlock(&q->mutex);
	return (void*)0;
}

int main() {
	q->front = 0;
	q->rear = 0;
	q->get = get;
	q->put = put;
	pthread_mutex_init(&(q->mutex), NULL);
	int i = 0;
	pthread_t pids[2];
	for(i = 0 ; i < 2; ++i) {
		pthread_create(&pids[0], NULL, put, (void*)&i);
	}
	printf("put\n");
	pthread_t pid[2];
	for(i = 0 ; i < 2; ++i) {
		pthread_create(&pid[0], NULL, get, NULL);
	}
	perror("error");
	return 0;
}
