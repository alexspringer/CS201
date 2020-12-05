.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -fgcse

all: hw4 hw44 hw48

hw4: hw4.o mult.o
	gcc -g -o hw4 $(CFLAGS) hw4.o mult.o

hw44: hw4.o Mult4.o
	gcc -g -o hw44 $(CFLAGS) hw4.o Mult4.o

hw48: hw4.o Mult8.o
	gcc -g -o hw48 $(CFLAGS) hw4.o Mult8.o

hw4.o: hw4.c
	gcc -c -g -o hw4.o $(CFLAGS) hw4.c

mult.o: mult.c
	gcc -c -g -o mult.o $(CFLAGS) mult.c

Mult4.o: Mult4.c
	gcc -c -g -o Mult4.o $(CFLAGS) Mult4.c

Mult8.o: Mult8.c
	gcc -c -g -o Mult8.o $(CFLAGS) Mult8.c

clean:
	rm -f *.o hw4 hw44 hw48
