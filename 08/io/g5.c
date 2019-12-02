#include "head.h"


volatile sig_atomic_t flag = 0;



void sig(int signo) {
	printf("sig : global = 1\n");
	flag = 1;
}

int main() {
	signal(SIGINT, sig);
	for(int i = 0; i != 100; i++) {
		sleep(1);
		printf("%d : main global = %d\n", i, flag);
		flag = 0;
	}
	return 0;
}
