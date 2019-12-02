#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
	char buf[32];
	int s = inet_pton(AF_INET, "128.2.210.175", buf);
	if(s <= 0) 
		fprintf(stderr, "Not in presentation format\n");
	buf[8] = 0;
	char str[32];
	inet_ntop(AF_INET, buf, str, 8);
	str[8] = 0;
	printf("%s\n", str);
}
