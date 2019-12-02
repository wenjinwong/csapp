#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void bufoverflow() {
	char buf[64];

	gets(buf); /* Here is the stack buffer overflow bug */
	return ;
}

int main() {
	bufoverflow() 
		;
}
