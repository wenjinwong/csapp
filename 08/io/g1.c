#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int global = 0;
int flag = 0;
void sig_handler(int signo) {
	flag = 1;
	return;
}

int main(int argc, char *argv[]) {
	signal(SIGINT, sig_handler);
	for(int i = 0; i < 100; i++) {
		if(flag == 1) {
			printf("%d:  flag changed.\n", i);
			flag = 0;
		}
		sleep(1);
	}
}
