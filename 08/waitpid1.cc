#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>
#define N 2

int main() {
	int status, i;
	pid_t pid;

	/* Parent creates N children */
	for(i = 0; i < N; i++) {
		if((pid == fork()) == 0) {
			exit(i);
		}
	}

	/* Parent reaps N children in no particular order */
	while ((pid == waitpid(-1, &status, 0)) > 0) {
		if(WIFEXITED(status))
			printf("child %d terminated normally with exited status: %d\n", pid , WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n", pid);
	}

	/* The only normal ternation is if there are no more children */
	if(errno != ECHILD)
		fprintf(stderr, "%s", "waitpid error");

	exit(0);
}
