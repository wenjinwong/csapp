#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<errno.h>


volatile sig_atomic_t pid;

void sigchld_handler(int s) {
	int olderrno = errno;
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

	while(1) {
		sigprocmask(SIG_BLOCK, &mask, &prev);
		if(fork() == 0) 
			exit(0);

		pid = 0;
		sigprocmask(SIG_SETMASK, &prev, NULL); /* Unblock SIGCHLD */

		/* Wait for SIGCHLD TO BR recerived (wastful) */
		while(!pid){;};

		/* Do some work after receiving SIGCHLD */
		printf(".");
	}
	exit(0);
}
