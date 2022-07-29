	global binarySearch

	section .text
	;; rdi = arr. rsi = left, rdx = right, rcx = target
binarySearch:
start:
	xor r10, r10
	cmp rdx, rsi		;if right < left, it's not in array
	jl notFound
	mov r10, rdx 		;r10 keeps track of middle index
	sub r10, rsi
	shr r10, 1
	add r10, rsi
	cmp [rdi+r10*4], ecx	;comparing middle value and target
	je done
	jl right
	jg left
left:
	mov rdx, r10
	sub rdx, 1
	jmp start
right:
	mov rsi, r10
	add rsi, 1
	jmp start
done:
	mov rax, r10
	ret
notFound:
	mov rax, -1
	ret
