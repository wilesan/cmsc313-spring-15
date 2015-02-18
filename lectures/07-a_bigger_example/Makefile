################################################################
#
# Makefile for toupper.asm
# Last Edited 2/5/2015
#
################################################################

CC=gcc
AS=nasm
LD=ld
ASFLAGS=-f elf -g -F dwarf
LDFLAGS=-melf_i386
.PREFIXES= .c .o .asm

ASM_SOURCE=escape.asm

C_SOURCE=my_c.c

ALL_TARGETS=escape

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

C_OBJECTS=${ASM_SOURCE:.c=.o}

all: ${ALL_TARGETS}

%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

${ALL_TARGETS}: ${ASM_OBJECTS} ${C_OBJECTS}
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS}

