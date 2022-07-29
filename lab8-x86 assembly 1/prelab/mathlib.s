	global product

	section .text
product:
	xor	rax, rax
	xor	r10, r10
start1:
	cmp	r10, rsi
	je	done1
	add	rax, rdi
	inc	r10
	jmp	start1
done1:

	ret

	global power

	section .text
power:
	
start2:
	cmp	rsi, 0
	je	done2
	dec	rsi
	call	start2
	mov	rsi, rax
	call	product
	ret
done2:
	mov	rax,1
	ret
	
	
