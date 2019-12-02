#include"head.h"
int global = 5;
void sig(int signo) {
	sigset_t oldset, newset;
	sigemptyset(&newset);
	sigfillset(&newset);
	sigaddset(&newset, SIGINT);
	sigdelset(&newset, SIGPIPE);
	sigismember(&newset, SIGINT);
	sigprocmask(SIG_SETMASK, &newset, &oldset);
	sleep(5);
	printf("signal\n");
	sigprocmask(SIG_SETMASK, &oldset, NULL);
}

int main() {
	signal(SIGINT, sig);
	sigset_t oldset, newset;
	sigemptyset(&newset);
	sigfillset(&newset);
	sigaddset(&newset, SIGINT);
	sigdelset(&newset, SIGPIPE);
	sigismember(&newset, SIGINT);
	sigprocmask(SIG_SETMASK, &newset, &oldset);
	global = 10;
	sigprocmask(SIG_SETMASK, &oldset, NULL);
	sleep(5);
	printf("main\n");
}
