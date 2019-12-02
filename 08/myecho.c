#include<stdio.h>

int main(int argc, char *argv[], char *envp[]) { // test
	for(int i = 0; i < argc; ++i) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	int i = 0;
	printf("Environment variables:\n");
	while(envp[i]) printf("env[%d]: %s\n", i, envp[i++]);
		

}
