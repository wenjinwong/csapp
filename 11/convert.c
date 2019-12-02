#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	unsigned char buf[sizeof(struct in6_addr)];
	int domain, s;
	char str[INET6_ADDRSTRLEN];
	if(argc != 3) {
		fprintf(stderr, "Usage : %s {i4 | i6| <num> } string \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	domain = (strcmp(argv[1], "i4") == 0) ? AF_INET : (strcmp(argv[1], "i6") == 0) ? AF_INET6 : atoi(argv[1]);

	s = inet_pton(domain, argv[2], buf);
	printf("%s\n", buf);
	if(s <= 0) {
		if(s == 0)
			fprintf(stderr, "Not in presentation format\n");
		else
			perror("inet_pton\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", str);

	exit(EXIT_SUCCESS);
}

