#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

volatile sig_atomic_t pid;

void sigchld_handler(int s) {
	int olderrno = errno;
	printf("handler\n");
	pid = waitpid(-1, NULL, 0);
	errno = olderrno;
}

void sigint_handler(int s) {
}

int main(int argc, char **argv) {
	sigset_t mask, prev;

	signal(SIGCHLD, sigchld_handler);
	signal(SIGINT, sigint_handler);
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	int i =1;
	while(i) {
		i--;
		sigprocmask(SIG_BLOCK, &mask, &prev); /* BLOCK SIGCHLD */
		if(fork() == 0) /* Child */
			exit(0);

		/* wait for SIGCHLD to be received */
		pid = 0;
		printf("suspend\n");
		while(!pid) sigsuspend(&prev);

		/* optionlly unblock SIGCHLD */
		sigprocmask(SIG_SETMASK, &prev, NULL);
		sleep(2);
		printf(".");
		sleep(3);
	}
	exit(0);
}
