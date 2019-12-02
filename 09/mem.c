#include<string.h>
#include<stdio.h>

int main() {
	char *delim;
	char buf[128] = "01  23 456789\0";
	delim = strchr(buf, ' ');
	*delim = '#';
	printf("%s", buf);
}
