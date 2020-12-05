//Alex Springer, 5/24/17, cs 201, HW3, crca1.s



.global crcInit
.global crcFast

#11010101 - 213 (If result crca1.S)
#11010101 - 2 comp -43. (If result in crc.c)

.text
	crcInit:
		movq $0, %rbx #int dividend
		movq $0, %r12 #char remainder
		movq $0, %r13 #char bit
		movq $table, %r14 #crcTable base
		pushq %rbp
		movq $0, %rbp

		loopOuter:
			movb %bl, %r12b
			movb $8, %r13b

			loopInner:
				movb %r12b, %bpl
				andb $0x80, %bpl
				jnz if
				jmp else
		
				if:
					salb $1, %r12b
					xorb $0xD5, %r12b
					jmp done

				else:
					salb $1, %r12b

				done:
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
