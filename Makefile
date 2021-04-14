all: lab3.o struct.o
	gcc lab3.o struct.o -o lab3

lab3.o: lab3.c
	gcc -c lab3.c

struct.o: struct.c
	gcc -c struct.c
