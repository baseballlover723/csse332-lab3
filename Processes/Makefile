CC = gcc

CFLAGS = -Wall -c -g

## A list of options to pass to the linker. 
LDFLAGS = -Wall -g -lm

## Name the executable program, list source files
PROG = processes
SRCS = processes.c 

## Build the program from the object files (-o option)
$(PROG): processes.o
	$(CC) processes.o -o $(PROG) $(LDFLAGS)

processes.o: processes.c processes.h
	$(CC) $(CFLAGS) processes.c -c -o processes.o

## Remove all the compilation and debugging files
clean: 
	rm -f core $(PROG) processes.o *~
