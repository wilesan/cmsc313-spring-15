################################################################
#
# Makefile for subroutines lecture
# Last Edited 2/18/2015
#
################################################################

CC=gcc
AS=nasm
LD=ld
MAKE=make
ASFLAGS=-f elf -g -F dwarf
LDFLAGS=-melf_i386
.PREFIXES= .c .o .asm

ASM_SOURCE=recurse.asm subroutine.asm

ALL_TARGETS=recurse subroutine

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

all: ${ALL_TARGETS} backup/rep backup/switch backup/toupper2

backup/rep backup/switch backup/toupper2:
	cd backup; ${MAKE}
	
%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

recurse: recurse.o
	${LD} ${LDFLAGS} -o $@ $<

subroutine: subroutine.o
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS}

