################################################################
#
# Makefile for subroutines/backup
# Last Edited 2/18/2015
#
################################################################

CC=gcc
AS=nasm
LD=ld
ASFLAGS=-f elf -g -F dwarf
LDFLAGS=-melf_i386
.PREFIXES= .c .o .asm

ASM_SOURCE=rep.asm switch.asm toupper2.asm

ALL_TARGETS=rep switch toupper2

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

all: ${ALL_TARGETS}

rep.o: rep.asm
	${AS} ${ASFLAGS} $< -o $@

switch.o: switch.asm
	${AS} ${ASFLAGS} $< -o $@  -l switch.lst

toupper2.o: toupper2.asm
	${AS} ${ASFLAGS} $< -o $@

rep: rep.o
	${LD} ${LDFLAGS} -o $@ $<

switch: switch.o
	${LD} ${LDFLAGS} -o $@ $<

toupper2: toupper2.o
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS} *.lst

