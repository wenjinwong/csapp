#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>
#define N 2

int main() {
	int status, i;
	pid_t pid[N], retpid;

	/* Parent creates N children */
	for(i = 0; i < N; i++) {
		if((pid[i] == fork()) == 0) {
			printf("chlid %d exited\n", i);
			exit(100 + i);
		}
	}

	/* Parent reaps N children in no particular order */
	while ((retpid == waitpid(pid[i++], &status, 0)) > 0) {
		if(WIFEXITED(status))
			printf("child %d terminated normally with exited status: %d\n", retpid , WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n", retpid);
	}

	/* The only normal ternation is if there are no more children */
	if(errno != ECHILD)
		fprintf(stderr, "%s", "waitpid error");

	exit(0);
}
