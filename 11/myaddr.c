#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv) {
	struct in_addr inaddr;
	uint32_t addr;
	char buf[100];
	sscanf(argv[1], "%x", &addr);
	inaddr.s_addr = htonl(addr);
	inet_ntop(AF_INET, &inaddr, buf, 100);
	printf("%s", buf);
}


