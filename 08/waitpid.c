#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	pid_t  pid[10],retpid;
	for(int i = 0; i < 10; i++) {
		if((pid[i] = fork()) == 0) {
			printf("child: %d   %d\n", i, getpid());
			exit(1);
		} 
	}
	int i = 0;
	while((retpid = waitpid(pid[i], NULL, 0)) > 0) {
		printf("%d: parent received %d\n", retpid, i);
		i++;
	}
	return 0;
}
