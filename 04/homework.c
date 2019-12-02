#include<assert.h>
#include<stdio.h>
/* 4.46
 * a.no
 * b. movq %reg, -8(%rsp), subq $8, %rsp
 *
 *
 * 4.47
 * a.no
 * b.subq $8, %rsp, movq -8(%rsp), %reg
 *
 * 4.47
 * a. code as follow
 */
void bubble_b(long *data, long count) {
	long i, last;
	for(last = count -1; last > 0; last--) {
		for(i = 0; i < last; i++) {
			if(*(data+i + 1) < *(data+i)) {
				long t = *(data+i+1);
				*(data+i+1) = *(data+i);
				*(data+i) = t;
			}
		}
	}
}

/*
 * b.
 * LOOP METHOD 
 *
 * INNER:
 * SOME OPERATION
 * COMP $0, %RCX
 * JG INNER
 * SUDQ $1, %RSI
 * COMP %0, %RSI
 * JG   INNER
 * RET
 * cmovb rdatai+1, datai
 * comvb datai,  datai+1
 * # Execution begins at address 0
 * .pos
 * irmovq stack, %rsp
 * call   main
 * halt
 * .align 8
 * data:
 * .quad 0xa000a000a000
 * .quad 0x0b
 * .quad 0x00c
 * .quad 0x000d
 * main:
 * irmovq data, %rdi
 * irmovq $4, %rsi
 * call bubble_p
 * ret
 *
 * bubble_p:
 * rrmovq %rsi, %r9
 * irmovq $1, %r11
 * subq   %r11, %r9
 * jmp L2
 * L4:
 * rrmovq %rdi, %rdx
 * rrmovq %rax, %rcx
 * irmovq $8, %r10
 * loop:
 * subq %r11, %rcx
 * jl end_loop
 * addq %r10, %rdx
 * jmp loop
 * end_loop
 * mrmovq (%rdx), %r8
 * rrmovq %rdx, %rsi
 * addq %r10, %rsi
 * mrmovq (%rsi), %rcx
 * rrmovq %rcx, %r10
 * subq %r8, %r10
 * jge L3
 * ...
 *

 
int main() {
	long arr[] = {2, 1, 3, 5, 4};


	bubble_b(arr, sizeof(arr)/sizeof(long));
	assert(arr[0] == 1 && arr[4] == 5);
}
