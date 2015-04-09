################################################################
#
#
################################################################

CC=gcc
AS=nasm
CFLAGS=-m32 -g
ASFLAGS=-f elf -g -F dwarf

.PREFIXES= .c .o

ALL_TARGETS=sorter sorter_nostdlib

C_SOURCE=sorter.c

ASM_SOURCE=library.asm

ASM_OBJECTS={ASM_SOURCE:.asm=.o}

C_OBJECTS=${C_SOURCE:.c=.o}

all: ${ALL_TARGETS}

%.o: %.c
	${CC} -fno-stack-protector -c ${CFLAGS} $< -o $@

%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

sorter: sorter.o
	${CC} ${CFLAGS} -o $@ $<

sorter_nostdlib: sorter.o library.o
	${CC} ${CFLAGS} -nostdlib -o $@ sorter.o library.o
	
clean:
	rm -f *.o ${ALL_TARGETS}

