################################################################
#
# Makefile for ASM Language IV
# Last Edited 2/12/2015
#
################################################################

AS=nasm
LD=ld
ASFLAGS=-f elf -g -F dwarf
LDFLAGS=-melf_i386
.PREFIXES= .o .asm

ALL_TARGETS=escape

ASM_SOURCE=escape.asm

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

all: ${ALL_TARGETS}

%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

escape: escape.o
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS} *.lst

