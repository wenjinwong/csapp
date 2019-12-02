#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#define N 2
int main() {
	int status, i;
	pid_t pid;
	i = 0;
	while(i < N) {
		pid = fork();
		if(pid == 0) {
		/* Children will execute this */
			sleep(1);
			printf("child %d    %d\n", getpid(), i);
			exit(0);
		}
		else{
		    waitpid(pid, &status, WUNTRACED | WCONTINUED);
		    printf("%d  %d\n", i, pid);
			fflush(stdout);
		    i++;
		}
	}
}
