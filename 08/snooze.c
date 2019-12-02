#include<unistd.h>
#include<signal.h>
#include<stdio.h>
int snooze(unsigned int secs) {
	unsigned int remain = 0;
	remain = sleep(secs);
	printf("Slept for %d of %d.\n", secs -remain, secs);
	return remain;
}

void handler(int signo) {
	printf("handler\n");
}

int main(int argc, char *argv[]) {
	signal(SIGINT, handler);
	snooze(5);
}
