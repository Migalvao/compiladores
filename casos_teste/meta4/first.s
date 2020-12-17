	.text
	.file	"first.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI0_0:
	.quad	4611911198408756428     # double 2.0999999999999996
.LCPI0_1:
	.quad	4607182418800017408     # double 1
.LCPI0_2:
	.quad	4610334938539176755     # double 1.7
.LCPI0_3:
	.quad	4621819117588971520     # double 10
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movsd	.LCPI0_1(%rip), %xmm1   # xmm1 = mem[0],zero
	movsd	.LCPI0_2(%rip), %xmm2   # xmm2 = mem[0],zero
	movsd	.LCPI0_3(%rip), %xmm3   # xmm3 = mem[0],zero
	movl	$0, -28(%rbp)
	movb	$10, -1(%rbp)
	movsd	%xmm3, -16(%rbp)
	movl	$5, -20(%rbp)
	cmpl	$0, -20(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -24(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm2, -16(%rbp)
	movsd	%xmm1, -16(%rbp)
	movb	$-1, -1(%rbp)
	movsd	%xmm0, -16(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movsbl	-1(%rbp), %eax
	cmpl	$90, %eax
	jg	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movsbl	-1(%rbp), %edi
	movb	$0, %al
	callq	putchar
	movsbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
	jmp	.LBB0_1
.LBB0_3:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 10.0.0-4ubuntu1 "
	.section	".note.GNU-stack","",@progbits
