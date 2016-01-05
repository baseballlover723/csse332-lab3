CC = gcc

CFLAGS = -Wall -c -g

## A list of options to pass to the linker. 
LDFLAGS = -Wall -g -lm

## Name the executable program, list source files
PROG = processes

all: program1 program2
## Build the program from the object files (-o option)
program1: processes.o
	$(CC) processes.o -o $(PROG) $(LDFLAGS)

processes.o: processes.c processes.h
	$(CC) $(CFLAGS) processes.c -c -o processes.o

## Name the executable program, list source files
PROG2 = myCopy

## Build the program from the object files (-o option)
program2: myCopy.o
	$(CC) myCopy.o -o $(PROG2) $(LDFLAGS)

myCopy.o: myCopy.c
	$(CC) $(CFLAGS) myCopy.c -c -o myCopy.o

## Remove all the compilation and debugging files
clean: 
	rm -f core $(PROG) processes.o *~
	rm -f core $(PROG2) myCopy.o *~
