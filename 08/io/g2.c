#include"head.h"
#include<errno.h>

void sig(int signo) {
	int prev_errno = errno;
	errno = 5;
	perror("signal\n");
	printf("signal received\n");
	errno = prev_errno;
	return;
}


int main() {
	errno = 10;
	signal(SIGINT, sig);
	sleep(10);
	perror("error ?\n");
	sleep(10);
}
