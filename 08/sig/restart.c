#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<setjmp.h>

sigjmp_buf buf;

void handler(int sig) {
	siglongjmp(buf, 1);
}

int main() {
	if(!sigsetjmp(buf, 1)) {
		signal(SIGINT, handler);
		write(STDOUT_FILENO, "starting\n", 15);
	}
	else 
		write(STDOUT_FILENO, "restarting\n",15);

	while(1) {
		sleep(1);
		write(STDOUT_FILENO, "processing...\n", 15);
	}
	exit(0); /* Control never reaches here */
}
