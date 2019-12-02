#include<string.h>
#include<stdio.h>


int main(void) {
	char buf[100];
	sprintf(buf, "%s %d", "one", 5);
	sprintf(buf, "%s", "added");
	printf("%s", buf);
}
