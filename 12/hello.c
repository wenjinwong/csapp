#include"csapp.h"
void *thread(void *vargp);

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, thread, &tid);
	pthread_join(tid, NULL);
	printf("%d thread exited\n");
	exit(0);
}

void *thread(void *vargp) /* Thread routine */
{
	
	printf("%d hello world\n", pthread_self());
	return NULL;
}
