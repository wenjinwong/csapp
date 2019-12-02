#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char **argv) {
	char *env;
	env = getenv("QUERY_STRING");	
	write(1, "        <h1> afdfaf </h1>           CGI BIN\n", 100);
	
	write(2, "        <h1> afdfaf </h1>           CGI BIN\n", 100);
	return 0;
}
