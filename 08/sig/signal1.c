/* WARNING: This code is buggy! */
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
void handler1(int sig) {
	int olderrno = errno;

	if(waitpid(-1, NULL,0) < 0)
		printf("waitpid error\n");
	write(STDERR_FILENO, "handler reaped child\n", 32);
	sleep(1);
	errno = olderrno;
}


void handler2(int sig) {
	int olderrno = errno;

	while (waitpid(-1, NULL, 0) > 0) {
		write(STDERR_FILENO, "Handler reaped child \n", 32);
		fflush(stderr);
	}

	if (errno != ECHILD) {
		write(STDERR_FILENO, "waitpid error\n", 32);
		fflush(stderr);
	}
	sleep(2);
	errno = olderrno;
}

#define MAXBUF 128
int main() {
	int i, n;
	char buf[MAXBUF];

	if(signal(SIGCHLD, handler2) == SIG_ERR)
//		perror("signal error\n\n");
;
	/* Parent creates children */
	for(i = 0; i < 3; i++) {
		if(fork() == 0) {
			printf("Hello from child %d\n", (int)getpid());
			fflush(stderr);
			exit(0);
		}
	}

	/* Parent waits for terminal input and then processes it */
	if((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
		//perror("read");
		printf("read error\n");
	printf("Parent processing input\n");
	while(1)
		;
	exit(0);
}

