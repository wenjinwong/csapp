#include<unistd.h>
#include<stdlib.h>
#include<string.h>

ssize_t sio_strlen(char *s) {
	return strlen(s);
}

ssize_t sio_puts(char s[]) {
	return write(STDOUT_FILENO, s, sio_strlen(s));
}

ssize_t sio_putl(long v) { /* Put long */
	char s[128];

	sio_ltoa(v, s, 
