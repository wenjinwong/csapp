#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#include<fcntl.h>
#include<errno.h>
int main(int argc, char *argv[]) {
	char buf[102400];
	int fd =open(argv[1], O_RDONLY, 0);
	if(fd <= 0) 
		perror("open arg error");
	read(fd, buf, 102400);
	int fd2 = open("tmp.jpg", O_RDWR, O_CREAT);
	if(fd2 <= 0) 
		perror("tmp error");
	write(fd2, buf , 102400);
	perror("see");
}
