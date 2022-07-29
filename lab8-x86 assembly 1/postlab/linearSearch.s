	global linearSearch

	section .text

; Parameter 1 is pointer to array (a[i]) rdi
; Parameter 2 is size of array, rsi
; Parameter 3 is value, edx
linearSearch:
	xor r10, r10
start:
	cmp r10, rsi		;compare current address to final address
	je didNotFind		;if current>final, did not find
	cmp [rdi], edx		;compare value in current to value
	je found		;if it's equal you found
	add rdi, 4		;add 4 to mem addy
	add r10, 1
	jmp start		;loop

found:
	mov rax, r10		;move 
	ret
didNotFind:
	mov rax, -1
	ret
