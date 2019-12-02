#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>


int main(int argc, char **argv) {
	struct in_addr inaddr;
	uint32_t addr;
	char buf[100];

	inet_pton(AF_INET, argv[1], &inaddr);
	int local = ntohl(inaddr.s_addr);
	printf("%x\n", local);
}
