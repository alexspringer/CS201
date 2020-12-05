//Optimised version of crc1a.S, Alex Springer, cs201, 5/24/17, hw3



.global crcInit
.global crcFast



.text
	crcInit:
		movq $0, %rbx #int dividend
		movq $0, %r12 #char remainder
		movq $0, %r13 #char bit
		movq $table, %r14 #crcTable base
		movq $0xD5, %rax #temp
		pushq %rbp
		movq $0, %rbp #used for conditional move

		loopOuter:
			movb %bl, %r12b
			movb $8, %r13b

			loopInner:
				movb %r12b, %bpl
				salb $1, %r12b
				andb $0x80, %bpl
				cmovnz %rax, %rbp
				xorb %bpl, %r12b


				decb %r13b
				cmpb $0, %r13b
				jg loopInner

			movb %r12b, (%r14, %rbx, 1)

			incl %ebx
			cmpl $256, %ebx
			jl loopOuter		
		popq %rbp
		ret



	crcFast:
		#char * message = rdi
		#long nBytes = rsi
		movq $0, %rbx #unsigned char data
		movq $0, %r12 #char remainder
		movq $0, %r13 #long byte

		loopFast:
			#message[byte] ^ remainder
			xorb (%rdi, %r13, 1), %r12b

			#data = remainder
			movb %r12b, %bl

			#remainder = crcTable[data]
			movb (%r14, %rbx, 1), %r12b

			incq %r13
			cmpq %r13, %rsi
			jg loopFast

		movb %r12b, %al
		ret



.data
	table:
		.rept 256
		.byte 0
		.endr
