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

ALL_TARGETS=recurse subroutine rep switch toupper2

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
	
recurse.o: recurse.asm
	${AS} ${ASFLAGS} $< -o $@

subroutine.o: subroutine.asm
	${AS} ${ASFLAGS} $< -o $@

recurse: recurse.o
	${LD} ${LDFLAGS} -o $@ $<

subroutine: subroutine.o
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS}

