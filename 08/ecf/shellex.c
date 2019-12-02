#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define MAXLINE 1024
#define MAXARGS 16
/* Function protypes */
char **environ;
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main() {
	char cmdline[MAXLINE]; /* Command line */

	while(1) {
		/* Read */
		printf("> ");
		fgets(cmdline, MAXLINE, stdin);
		if(feof(stdin))
			exit(0);

		/* Evalute */
		eval(cmdline);
	}
}


void eval(char *cmdline) {
	char *argv[MAXARGS];/* Argument list execve() */
	char buf[MAXLINE];	/* Holds modified command line */
	int bg;				/* Should the job run in bg or fg? */
	pid_t pid;			/* Process id */

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if(argv[0] == NULL)
		return; /* Ignore empty lines */

	if(!builtin_command(argv)) {
		if((pid = fork()) == 0) {	/* Child runs user job */
			if(execve(argv[0], argv, environ) < 0) {
				printf("%s: Command not found,\n", argv[0]);
				exit(0);
			}
		}

		/*Parent waits for foreground job to terminate */
		if(!bg) {
			int status;
			if(waitpid(pid, &status, 0) < 0) 
				fprintf(stderr, "%s\n", "waitfg: waitpid error");
		}
		else
			printf("%d %s", pid, cmdline);
	}
	return;
}

int builtin_command(char **argv) {
	if(!strcmp(argv[0], "quit")) 
		exit(0);
	if(!strcmp(argv[0], "&"))
		return 1;
	return 0;					/* Not a builtin command */
}

/* Parse line - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) {
	char *delim;
	int argc;
	int bg;

	buf[strlen(buf) - 1] = ' ';
	while(*buf && (*buf == ' '))
		buf++;

	/* Build the argv list */
	argc = 0;
	while ((delim = strchr(buf, ' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' ')) /* Ignore spaces */
			buf++;
	}
	argv[argc] = NULL;

	if(argc == 0) 
		return 1;

	if((bg = (*argv[argc-1] == '&')) != 0)
		argv[--argc] = NULL;
	return bg;
}
