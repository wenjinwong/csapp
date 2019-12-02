#include "csapp.h"
#include "sbuf.h"

/* Create an empty, bounded, shared FIFO buffer with
 * n slots
 */
void sbuf_init(sbuf_t *sp, int n) {
	sp->buf = calloc(n, sizeof(int));
	sp->n = n;		/* Buffer holds max of n items */
	sp->front = sp->rear = 0;
	sem_init(&sp->mutex, 0, 1);
	sem_init(&sp->slots, 0, n);
	sem_init(&sp->items, 0, 0);
}

/* Clean up buffer sp */
void sbuf_deinit(sbuf_t *sp) {
	free(sp->buf);
}

/* Insert item onto the rear of shared buffer sp */
void sbuf_insert(sbuf_t *sp, int item) {
	P(&sp->slots);
	P(&sp->mutex);
	sp->buf[(++sp->rear)%(sp->n)] = item;
	V(&sp->mutex);
	V(&sp->mutex);
}

/* Remove and return the first item from buffer sp */
int sub_remove(sbuf_t *sp) {
	int item;
	P(&sp->items);
	P(&sp->mutex);
	item = sp->buf[(++sp->front)%(sp->n)];
	V(&sp->mutex);
	V(&sp->slots);
	return item;
}



