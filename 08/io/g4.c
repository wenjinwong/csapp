#include "head.h"
#include<signal.h>
volatile int global = 0;

void sig(int signo) {
	printf("sig : global = 1\n");
	global = 1;
}

int main() {
	signal(SIGINT, sig);
	for(int i = 0; i != 100; i++) {
		sleep(1);
		printf("%d : main global = %d\n", i, global);
	}
	return 0;
}
