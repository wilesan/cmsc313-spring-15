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

ALL_TARGETS=jmp index1 index2

ASM_SOURCE=jmp.asm

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

all: ${ALL_TARGETS}

#%.o: %.asm
#	${AS} ${ASFLAGS} $< -o $@

index1.o: index1.asm
	${AS} ${ASFLAGS} $< -o $@ -l index1.lst

index1: index1.o
	${LD} ${LDFLAGS} -o $@ $<

index2.o: index2.asm
	${AS} ${ASFLAGS} $< -o $@ -l index2.lst

index2: index2.o
	${LD} ${LDFLAGS} -o $@ $<

jmp.o: jmp.asm
	${AS} ${ASFLAGS} $< -o $@ -l jmp.lst

jmp: jmp.o
	${LD} ${LDFLAGS} -o $@ $<

clean:
	rm -f *.o ${ALL_TARGETS} *.lst

