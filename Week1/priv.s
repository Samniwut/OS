	.arch armv8-a
	.file	"priv.c"
	.text
	.align	2
	.type	handler, %function
handler:
.LFB6:
	.cfi_startproc
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x29, x30, [sp, 80]
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	add	x29, sp, 80
	str	w0, [sp, 12]
	adrp	x0, :got:__stack_chk_guard
	ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x1, [x0]
	str	x1, [sp, 72]
	mov	x1, 0
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	add	x0, sp, 24
	ldr	q29, [x1]
	ldr	q30, [x1, 16]
	ldr	q31, [x1, 27]
	str	q29, [x0]
	str	q30, [x0, 16]
	str	q31, [x0, 27]
	add	x0, sp, 24
	mov	x2, 42
	mov	x1, x0
	mov	w0, 1
	bl	write
	mov	w0, 1
	bl	_exit
	.cfi_endproc
.LFE6:
	.size	handler, .-handler
	.section	.rodata
	.align	3
.LC0:
	.string	"caught signal: instruction blocked by CPU\n"
	.text
	.section	.rodata
	.align	3
.LC1:
	.string	"executing a privileged instruction..."
	.align	3
.LC2:
	.string	"(this demo needs an x86 CPU; skipped)"
	.align	3
.LC3:
	.string	"this line is never printed on x86"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	adrp	x0, handler
	add	x1, x0, :lo12:handler
	mov	w0, 11
	bl	signal
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	puts
	adrp	x0, :got:stdout
	ldr	x0, [x0, :got_lo12:stdout]
	ldr	x0, [x0]
	bl	fflush
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	puts
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	bl	puts
	mov	w0, 0
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.3.0-4ubuntu1) 15.3.0"
	.section	.note.GNU-stack,"",@progbits
