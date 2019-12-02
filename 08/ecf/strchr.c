#include<string.h>
#include<stdio.h>

int main() {
	char *buf = "one two  three\n";
	char *argv[5];
	printf("%p\n", argv[2]);
	char *delim;
	int i = 0;
	argv[0] = buf;
	printf("%s\n", argv[0]);
	while((delim = strchr(buf, ' '))) {
		argv[i] = buf;
		printf("%d     %s\n",i, argv[i]);
		buf = delim + 1;
		*(buf - 1) = '\0';
		while(*buf && (*buf == ' ')) buf++;
		i++;
	}
	
//	printf("%s \n%s\n", argv[0], argv[1]);
}
