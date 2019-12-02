#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#include<sys/types.h>
#include<string.h>
#define MAXLINE 1024


int main(int argc, char **argv) {
	struct addrinfo *p, *listp, hints;
	struct sockaddr_in *sockp;
	char buf[MAXLINE];
	int rc;

	if(argc != 2) {
		fprintf(stderr, "usage: %s <domain name> \n", argv[0]);
		exit(0);
	}

	/* Get a list of addrinfo records */
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
		exit(1);
	}
	/* Walk the list and display each associated IP address */
	for(p = listp; p; p = p->ai_next) {
		sockp = (struct sockaddr_in *)p->ai_addr;
		inet_ntop(AF_INET, &(sockp->sin_addr), buf, MAXLINE);
		printf("%s\n", buf);
	}
	freeaddrinfo(listp);
	exit(0);
}
