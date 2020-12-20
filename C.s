	.text
	.file	"C.c"
	.globl	func                    # -- Begin function func
	.p2align	4, 0x90
	.type	func,@function
func:                                   # @func
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -12(%rbp)
	movl	%esi, -8(%rbp)
	movl	-12(%rbp), %ecx
	shll	$1, %ecx
	movl	$8, %eax
	cltd
	idivl	-8(%rbp)
	addl	%eax, %ecx
	movl	%ecx, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	func, .Lfunc_end0-func
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI1_0:
	.quad	4607182418800017408     # double 1
.LCPI1_1:
	.quad	4627870829588250624     # double 25.5
.LCPI1_2:
	.quad	4607005807049924448     # double 0.98039215686274516
.LCPI1_3:
	.quad	-4631501856787818112    # double -0.099999999999999644
.LCPI1_4:
	.quad	4621875412584313651     # double 10.1
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
	movl	$0, -20(%rbp)
	movl	$0, -8(%rbp)
	movl	$53, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	$0, %al
	callq	putchar
	movsd	.LCPI1_4(%rip), %xmm0   # xmm0 = mem[0],zero
	movsd	%xmm0, -16(%rbp)
	movl	$43, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	$0, %al
	callq	putchar
	movsd	.LCPI1_2(%rip), %xmm0   # xmm0 = mem[0],zero
	movsd	.LCPI1_3(%rip), %xmm1   # xmm1 = mem[0],zero
	movsd	%xmm1, -16(%rbp)
	movl	$1, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movl	$96, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	$0, %al
	callq	putchar
	xorl	%eax, %eax
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movsd	.LCPI1_1(%rip), %xmm1   # xmm1 = mem[0],zero
	movsd	%xmm1, -16(%rbp)
	movl	$0, -4(%rbp)
	movl	$1, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movl	$1, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movl	$1, -4(%rbp)
	movl	$0, -4(%rbp)
	xorps	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$0, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %ecx
	andl	-8(%rbp), %ecx
	movl	%ecx, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.LBB1_2
# %bb.1:
	cmpl	$0, -8(%rbp)
	setne	%al
.LBB1_2:
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	orl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	movb	$1, %al
	jne	.LBB1_4
# %bb.3:
	cmpl	$0, -8(%rbp)
	setne	%al
.LBB1_4:
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	xorl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.LBB1_6
# %bb.5:
	cmpl	$0, -8(%rbp)
	movb	$1, %al
	jne	.LBB1_7
.LBB1_6:
	movl	-4(%rbp), %eax
	movl	-8(%rbp), %ecx
	andl	-4(%rbp), %ecx
	xorl	-8(%rbp), %ecx
	orl	%ecx, %eax
	cmpl	$0, %eax
	setne	%al
.LBB1_7:
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	$1, -4(%rbp)
	cmpl	$0, -4(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	$20, %edi
	movl	$4, %esi
	callq	func
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	$0, %al
	callq	putchar
	movb	$0, %al
	callq	getchar
	movl	%eax, -4(%rbp)
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	global,@object          # @global
	.data
	.globl	global
	.p2align	2
global:
	.long	6                       # 0x6
	.size	global, 4


	.ident	"clang version 9.0.1-12 "
	.section	".note.GNU-stack","",@progbits
