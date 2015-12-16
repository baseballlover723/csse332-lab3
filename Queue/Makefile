CC = gcc

## List of options to pass to the C compiler for all your source files
## -g Tells compiler to include extra debugging informaton in its output
## -Wall Give warnings of constructs that look suspect
## -ansi gives warnings or errors if the code does not follow ANSI standards
CFLAGS = -g -Wall -ansi

## A list of options to pass to the linker.  We have an empty list in this
## case
LDFLAGS =

## Name the executable program
PROG = driver

# Dependency Rules:
# A rule generally contains a dependency line and a command line
# dependency line <target>: <list_of_dependencies>
# command line \t<command>

## Build the program from the object files
$(PROG): driver.o queue.o
	$(CC) $(LDFLAGS) driver.o queue.o -o $(PROG)

## Rules for the source files.  They compile each X.c to make X.o
driver.o: driver.c queue.h
	$(CC) $(CFLAGS) driver.c -c -o driver.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) queue.c -c -o queue.o


## Remove all the compilation and debugging files
clean: 
	rm -f core $(PROG) driver.o queue.o *~

