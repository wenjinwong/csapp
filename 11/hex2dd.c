#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
	struct in_addr inaddr;
	uint32_t addr;
	char buf[100];
	if(argc != 2) {
		fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
		exit(0);
	}

	sscanf(argv[1], "%x", &addr);
	inaddr.s_addr = htonl(addr);

	if(!inet_ntop(AF_INET, &inaddr, buf, 100))
		printf("inet_ntop\n");
	printf("%s\n", buf);
	exit(0);
}
