/* 8.9
	AB  N
	AC  Y
	AD  Y
	BC  Y
	BD  Y
	CD  Y
*/

/* 8.10
 * A :
 * fork
 * B :
 * longjmp execve 
 * C :
 * setjmp
 */

/*
 * 8.11
 *
 * ----main-----printf
 *      |
 *      ---fork0 --- printf
 *      |   |---fork01
 *      ----fork1
 *      total : 4
 */

/* 
 * 8.12
 * 
 * ---main---p---p
 *    |
 *    ---fork0----p=---p
 *    |   |
 *    |   ---fork01---p---p
 *    |---fork1---p---p
 *
 *    8
 */

/* 8.13
 *
 * -----main---4---3
 *		|
 *		---fork0---(--i) == 2
 */

/* 8.14
 * ------main------printf
 *		 |
 *		 -----fork0--fork--printf---printf
 *		             |
 *		             --fork01---printf---printf
 *		total : 5
 */

/*
 * 8.15
 * --------main---fork-----printf
 *					|
 *					---fork0--fork---printf-- printf
 *							   |
 *							   ---printf--printf
 *			total : 5
 */

/*
 * 8.16
 * ---------main--fork()-wait-printf(2)
 *					|
 *					---fork0--0-exit---
 *
 *	2
 */

/* 8.17
 * main--pr(hello)--fork()--printf(0)--wait--status --bye
 *					|
 *					--child00--printf(1)--bye
 */

/*
 * 8.18
 * main--fork()--fork()---"1"--
 *       |        |-"0"
 *       --atexit--fork()--"1"--"2"
 *                  |
 *                  --"0"--"2"
 *
 *  E A C 
 */

/* 8.19
 * MAIN--fork--fork--
 *			|     |
 *			|     ---fork01--fork
 *			|--fork00--fork--	
 *						|
 *						--fork11
 *							   0 1 2 3 ... n
 *	num of processes equal to (1 2 4 8)
 *	2^n
 */

/*
 * 8.20
 */


/* 
 * 8.21
 * main--fork--"b"--wait--"c"
 *        |			 |
 *        --"a"--exit-
 *        a/b--b/a--c
 *        abc bac
 */

/* 
 * 8.23
 */
/*
#include<unistd.h>
#include<stdio.h>
#include<errno.h>

int main(int argc, const char* argv[], const char *envp[]) {
	if(execve("/bin/ls", argv, envp))
	{
		perror("Failed to execve /bin/ls:\n");
	}
	return 0;
}
*/
