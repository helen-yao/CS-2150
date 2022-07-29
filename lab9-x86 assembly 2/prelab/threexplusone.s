	;; optimizations: bit shift, memory heirarchy, used fewer instructions, only one register on stack
	global threexplusone

	section .text
	;; rdi, rsi, rdx, rcx, r, r9 modify: r10, r11
	
threexplusone:
	push r10		;memory heiarchy, only push/pop one register
	xor r10, r10		;r10 is counter, currently at 0
start:
	cmp rdi, 1
	je done
	
	test rdi, 1
	jz even

odd:
	add r10, 1
	imul rdi, 3
	add rdi, 1
	call threexplusone
	add r10, rax
	jmp start

even:
	add r10, 1
	shr rdi, 1		;used bit shift for division
	call threexplusone
	add r10, rax
	jmp start

done:
	mov rax, r10
	pop r10			;only one register on the stack
	ret 
