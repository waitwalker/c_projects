	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 1
	.globl	_staticTest             ## -- Begin function staticTest
	.p2align	4, 0x90
_staticTest:                            ## @staticTest
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	_staticTest.a(%rip), %eax
	addl	$1, %eax
	movl	%eax, _staticTest.a(%rip)
	movl	_staticTest.a(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -36(%rbp)
	movl	%edi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	_data8(%rip), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	_staticTest
	callq	_staticTest
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	callq	_test
	leaq	L_.str.3(%rip), %rdi
	leaq	_test(%rip), %rsi
	movb	$0, %al
	callq	_printf
	leaq	-32(%rbp), %rcx
	xorl	%esi, %esi
	movq	%rcx, %rdx
	movq	%rdx, %rdi
	movl	$20, %edx
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	callq	_memset
	movl	$5, -52(%rbp)
	movl	-52(%rbp), %esi
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	callq	_test1
	leaq	-32(%rbp), %rdi
	movl	-52(%rbp), %esi
	callq	_getMaxElement
	leaq	L_.str.4(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	-32(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	callq	_getMinElement
	leaq	L_.str.5(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	$0, -56(%rbp)
	movl	-56(%rbp), %esi
	leaq	L_.str.6(%rip), %rdi
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	_data1(%rip), %esi
	leaq	L_.str.7(%rip), %rdi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	_newData@GOTPCREL(%rip), %rcx
	movl	(%rcx), %esi
	leaq	L_.str.8(%rip), %rdi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	jne	LBB1_2
## %bb.1:
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
LBB1_2:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_test                   ## -- Begin function test
	.p2align	4, 0x90
_test:                                  ## @test
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_data1                  ## @data1
	.p2align	2
_data1:
	.long	100                     ## 0x64

	.p2align	2               ## @staticTest.a
_staticTest.a:
	.long	100                     ## 0x64

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\351\235\231\346\200\201\345\261\200\351\203\250\345\217\230\351\207\217:%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"\351\235\231\346\200\201\345\205\250\345\261\200\345\217\230\351\207\217:%d\n"

	.section	__DATA,__data
	.p2align	2               ## @data8
_data8:
	.long	188888                  ## 0x2e1d8

	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"Hello, World!\n"

L_.str.3:                               ## @.str.3
	.asciz	"\345\207\275\346\225\260\347\232\204\345\205\245\345\217\243\345\234\260\345\235\200:%p\n"

L_.str.4:                               ## @.str.4
	.asciz	"\346\225\260\347\273\204\345\205\203\347\264\240\346\234\200\345\244\247\345\200\274:%d\n"

L_.str.5:                               ## @.str.5
	.asciz	"\346\225\260\347\273\204\345\205\203\347\264\240\346\234\200\345\260\217\345\200\274:%d\n"

L_.str.6:                               ## @.str.6
	.asciz	"\345\261\200\351\203\250\345\217\230\351\207\217\344\270\215\345\210\235\345\247\213\345\214\226,\345\206\205\345\256\271\351\232\217\346\234\272:%d\n"

L_.str.7:                               ## @.str.7
	.asciz	"\346\231\256\351\200\232\345\205\250\345\261\200\345\217\230\351\207\217:%d\n"

L_.str.8:                               ## @.str.8
	.asciz	"extern\344\277\256\351\245\260\347\232\204\345\217\230\351\207\217\345\243\260\346\230\216:%d\n"

L_.str.9:                               ## @.str.9
	.asciz	"This is test.\n"

.subsections_via_symbols
