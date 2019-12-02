#include<unistd.h>
#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv, char **env) {
	if(argc != 2) {
		printf("usage: %s  %s", argv[0], "arg");
		return 0;
	}
	int fd;
	struct stat buf;
	
	if((fd = open(argv[1], O_RDWR, 0))) 
			printf("opened %s\n", argv[1]);
	


	fstat(fd, &buf);
	char *addr = NULL;
	addr = (char*)mmap(NULL, buf.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE , fd, 0);
	write(1, addr, buf.st_size);
}
