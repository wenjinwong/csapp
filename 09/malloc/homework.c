/*
 * 9.11
 * 0x027c
 * 00 0010 0111 1100
 * VPN		00 0010 01   =   0X9
 * TLB INDEX				 1
 * TLB TAG					 2
 * TLB HIT					 N
 * LACK						 N
 * PPN						 17
 * 01 0111 11 1100
 * 3C	15	17	NO   -
 *
 *
 * 00 0011 1010 1001
 * VPN		00 0011 10
 * i		2
 * tag		3
 *			n
 *			n
 *			0x11
 *			010001 101001
 *			01 
 *			a = 10
 *			0x11
 *			-
 */

/*
 * 0x0040
 * 00 0000 01 00 0000
 * 00 0000 01   1
 * tag	0 
 * n
 * y
 * -
 *  ----
 *  0
 *  --
 *
 */


/*
 * 9.14
 */
#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
void jello() {
	int fd = open("hello.txt", O_RDWR);
	char *pc =(char*)mmap(NULL, 100, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
	*pc = 'J';
	write(STDOUT_FILENO, pc, 10);
}

/*
 * 9.15
 * 8		1001
 * 16		10001
 * 24		11001
 * 32		100001
 */

/*
 * 9.16
 * 16
 * 16
 * 16
 * 16
*/

/* 9.17
static void *find_fit(size_t asize) {
	char *oldrover = rover;

	for(; GET_SIZE(HDRP(rover)) > 0; rover = NEXT_BLKP(rover)) 
		if(!GET_ALLOC(HDRP(rover)) && (asize <- GET_SIZE(HDRP(rover))))
			return rover;
	for(rover = heap_listp ; rover < oldrover ; rover = nezt_blkp(rober))
		if(!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
			return rover;
	return NULL;
}*/
int main() {
	jello();
}
	
