	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_rsum                   ## -- Begin function rsum
	.p2align	4, 0x90
_rsum:                                  ## @rsum
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	testq	%rsi, %rsi
	jle	LBB0_1
## %bb.2:
	cmpq	$4, %rsi
	jae	LBB0_4
## %bb.3:
	xorl	%eax, %eax
	jmp	LBB0_13
LBB0_1:
	xorl	%eax, %eax
	popq	%rbp
	retq
LBB0_4:
	movq	%rsi, %r8
	andq	$-4, %r8
	leaq	-4(%r8), %rdx
	movq	%rdx, %rcx
	shrq	$2, %rcx
	incq	%rcx
	movl	%ecx, %eax
	andl	$3, %eax
	cmpq	$12, %rdx
	jae	LBB0_6
## %bb.5:
	pxor	%xmm0, %xmm0
	xorl	%edx, %edx
	pxor	%xmm1, %xmm1
	testq	%rax, %rax
	jne	LBB0_9
	jmp	LBB0_11
LBB0_6:
	movl	$1, %edx
	subq	%rcx, %rdx
	leaq	-1(%rax,%rdx), %rcx
	pxor	%xmm0, %xmm0
	xorl	%edx, %edx
	pxor	%xmm1, %xmm1
	.p2align	4, 0x90
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	movdqu	(%rdi,%rdx,8), %xmm2
	paddq	%xmm0, %xmm2
	movdqu	16(%rdi,%rdx,8), %xmm0
	paddq	%xmm1, %xmm0
	movdqu	32(%rdi,%rdx,8), %xmm1
	movdqu	48(%rdi,%rdx,8), %xmm3
	movdqu	64(%rdi,%rdx,8), %xmm4
	paddq	%xmm1, %xmm4
	paddq	%xmm2, %xmm4
	movdqu	80(%rdi,%rdx,8), %xmm2
	paddq	%xmm3, %xmm2
	paddq	%xmm0, %xmm2
	movdqu	96(%rdi,%rdx,8), %xmm0
	paddq	%xmm4, %xmm0
	movdqu	112(%rdi,%rdx,8), %xmm1
	paddq	%xmm2, %xmm1
	addq	$16, %rdx
	addq	$4, %rcx
	jne	LBB0_7
## %bb.8:
	testq	%rax, %rax
	je	LBB0_11
LBB0_9:
	leaq	16(%rdi,%rdx,8), %rcx
	negq	%rax
	.p2align	4, 0x90
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	movdqu	-16(%rcx), %xmm2
	paddq	%xmm2, %xmm0
	movdqu	(%rcx), %xmm2
	paddq	%xmm2, %xmm1
	addq	$32, %rcx
	incq	%rax
	jne	LBB0_10
LBB0_11:
	paddq	%xmm1, %xmm0
	pshufd	$78, %xmm0, %xmm1       ## xmm1 = xmm0[2,3,0,1]
	paddq	%xmm0, %xmm1
	movq	%xmm1, %rax
	cmpq	%rsi, %r8
	je	LBB0_15
## %bb.12:
	subq	%r8, %rsi
	leaq	(%rdi,%r8,8), %rdi
LBB0_13:
	incq	%rsi
	.p2align	4, 0x90
LBB0_14:                                ## =>This Inner Loop Header: Depth=1
	addq	(%rdi), %rax
	addq	$8, %rdi
	decq	%rsi
	cmpq	$1, %rsi
	jg	LBB0_14
LBB0_15:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
