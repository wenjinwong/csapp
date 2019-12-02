#include<stdlib.h>
#include<socket.h>
#include<unistd.h>


int main() {
	struct sockaddr addr;
	int fd = socket(AF_INET, STREAM, 0);
	int status = connect(fd, &addr, sizeof(addr));
	if(status != 0)
		printf("connect error\n");
