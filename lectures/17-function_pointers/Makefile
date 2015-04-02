################################################################
#
# Makefile for function pointers lecture
# Last Edited 4/1/2015
#
################################################################

AS=nasm
CC=gcc
I2G=intel2gas
OBJDUMP=objdump
MAKE=make
GREP=grep
ASFLAGS=-f elf -g -F dwarf
CFLAGS=-m32
.PREFIXES= .c .o .asm

ALL_TARGETS=arraytest cfunc cfunc3 funcptr1 funcptr2 funcptr3 qsort1 qsort2 qsort3 printf1 printf2

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

C_OBJECTS=${C_SOURCE:.asm=.c}

all: ${ALL_TARGETS}

arraytest: arrayinc.asm arraytest.c
	$(AS) $(ASFLAGS) -o arrayinc.o arrayinc.asm
	$(CC) $(CFLAGS) -o arraytest arraytest.c arrayinc.o

cfunc: cfunc.c
	$(CC) $(CFLAGS) -g -c cfunc.c
	$(CC) $(CFLAGS) -S cfunc.c
	$(CC) $(CFLAGS) cfunc.o -o cfunc
	$(OBJDUMP) -d -S cfunc.o > cfunc_objdump.out
	$(GREP) -v .cfi cfunc.s > cfunc_grepd.s
	$(I2G) -g cfunc_grepd.s > cfunc.asm

cfunc3: cfunc3.c
	$(CC) $(CFLAGS) cfunc3.c -o cfunc3

printf1: printf1.asm
	$(AS) $(ASFLAGS) -o printf1.o printf1.asm
	$(CC) $(CFLAGS) -o printf1 printf1.o

printf2: printf2.asm
	$(AS) $(ASFLAGS) -o printf2.o printf2.asm
	$(CC) $(CFLAGS) -nostartfiles -o printf2 printf2.o

funcptr1: funcptr1.c
	$(CC) $(CFLAGS) -o funcptr1 funcptr1.c

funcptr2: funcptr2.c
	$(CC) $(CFLAGS) -o funcptr2 funcptr2.c

funcptr3: funcptr3.c
	$(CC) $(CFLAGS) -o funcptr3 funcptr3.c

qsort1: qsort1.c
	$(CC) $(CFLAGS) -o qsort1 qsort1.c

qsort2: qsort2.c
	$(CC) $(CFLAGS) -o qsort2 qsort2.c

qsort3: qsort3.c
	$(CC) $(CFLAGS) -o qsort3 qsort3.c
	
clean:
	rm -f *.o ${ALL_TARGETS} cfunc.s cfunc_grepd.s cfunc.asm cfunc_objdump.out

