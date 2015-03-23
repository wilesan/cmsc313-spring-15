################################################################
#
# Makefile for subroutines lecture
# Last Edited 3/23/2015
#
################################################################

CC=gcc
MAKE=make
ASFLAGS=-f elf -g -F dwarf
CFLAGS=-m32
.PREFIXES= .c .o .asm

C_SOURCE=array_of_strings1.c array_of_strings2.c array_of_strings3.c array_of_strings4.c array_of_strings5.c

ALL_TARGETS=array_of_strings1 array_of_strings2 array_of_strings3 array_of_strings4 array_of_strings5

all: ${ALL_TARGETS}

array_of_strings1: array_of_strings1.c
	${CC} ${CFLAGS} -o $@ $<

array_of_strings2: array_of_strings2.c
	${CC} ${CFLAGS} -o $@ $<

array_of_strings3: array_of_strings3.c
	${CC} ${CFLAGS} -o $@ $<

array_of_strings4: array_of_strings4.c
	${CC} ${CFLAGS} -o $@ $<

array_of_strings5: array_of_strings5.c
	${CC} ${CFLAGS} -o $@ $<
	
clean:
	rm -f *.o ${ALL_TARGETS}

