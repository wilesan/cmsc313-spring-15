################################################################
#
#
################################################################

CC=gcc
AS=nasm
LD=ld
ASFLAGS=-f elf -g -F dwarf
LDFLAGS=-melf_i386
CFLAGS=-m32 -g
.PREFIXES= .c .o .asm

ASM_SOURCE=spd.asm

ALL_TARGETS=spd

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

all: ${ALL_TARGETS}

%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

${ALL_TARGETS}: ${ASM_OBJECTS} data.o
	${LD} ${LDFLAGS} -o $@ $< data.o

clean:
	rm -f *.o ${ALL_TARGETS}

