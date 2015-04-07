################################################################
#
# Makefile for polymorphism lecture
# Last Edited 4/7/2015
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

C_OBJECTS=doarray.c funcptr2a.c 111/ll.c 111/main01.c 112/ll.c 112/main02.c 113/ll.c 113/main03.c \
	114/ll.c 114/main04.c 114/main05.c 114/main06.c 114/main07.c \
	115/ll.c 115/main08.c 115/main09.c 115/main10.c 115/main11.c \
	116/ll.c 116/main12.c 116/main13.c 116/main14.c 116/main15.c 116/main16.c \
	117/ll.c 117/ll_string.c 117/ll_list.c 117/ll_int.c 117/ll_double.c 117/main17.c 117/main18.c 117/main19.c 117/main20.c 117/main21.c
	

ASM_OBJECTS=do_array.asm main.asm

ALL_TARGETS=do_array_asm do_array_c 111/main01 112/main02 113/main03 114/main04 114/main05 114/main06 114/main07 \
	115/main08 115/main09 115/main10 115/main11 116/main12 116/main13 116/main14 116/main15 116/main16 \
	117/main17 117/main18 117/main19 117/main20 117/main21

ASM_OBJECTS=${ASM_SOURCE:.asm=.o}

C_OBJECTS=${C_SOURCE:.asm=.c}

%.o: %.asm
	${AS} ${ASFLAGS} $< -o $@

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<


all: ${ALL_TARGETS}

do_array_asm: funcptr2a.o do_array.o
	$(CC) $(CFLAGS) -o $@ funcptr2a.o do_array.o

do_array_c: main.o doarray.o
	$(CC) $(CFLAGS) -o $@ main.o doarray.o

111/main01: 111/ll.o 111/main01.o
	$(CC) $(CFLAGS) -o $@ 111/main01.o 111/ll.o

112/main02: 112/ll.o 112/main02.o
	$(CC) $(CFLAGS) -o $@ 112/main02.o 112/ll.o

113/main03: 113/ll.o 113/main03.o
	$(CC) $(CFLAGS) -o $@ 113/main03.o 113/ll.o

114/main04: 114/ll.o 114/main04.o
	$(CC) $(CFLAGS) -o $@ 114/main04.o 114/ll.o

114/main05: 114/ll.o 114/main05.o
	$(CC) $(CFLAGS) -o $@ 114/main05.o 114/ll.o

114/main06: 114/ll.o 114/main06.o
	$(CC) $(CFLAGS) -o $@ 114/main06.o 114/ll.o

114/main07: 114/ll.o 114/main07.o
	$(CC) $(CFLAGS) -o $@ 114/main07.o 114/ll.o

115/main08: 115/ll.o 115/main08.o
	$(CC) $(CFLAGS) -o $@ 115/main08.o 115/ll.o

115/main09: 115/ll.o 115/main09.o
	$(CC) $(CFLAGS) -o $@ 115/main09.o 115/ll.o

115/main10: 115/ll.o 115/main10.o
	$(CC) $(CFLAGS) -o $@ 115/main10.o 115/ll.o

115/main11: 115/ll.o 115/main11.o
	$(CC) $(CFLAGS) -o $@ 115/main11.o 115/ll.o

116/main12: 116/ll.o 116/main12.o
	$(CC) $(CFLAGS) -o $@ 116/main12.o 116/ll.o

116/main13: 116/ll.o 116/main13.o
	$(CC) $(CFLAGS) -o $@ 116/main13.o 116/ll.o
	
116/main14: 116/ll.o 116/main14.o
	$(CC) $(CFLAGS) -o $@ 116/main14.o 116/ll.o
	
116/main15: 116/ll.o 116/main15.o
	$(CC) $(CFLAGS) -o $@ 116/main15.o 116/ll.o

116/main16: 116/ll.o 116/main16.o
	$(CC) $(CFLAGS) -o $@ 116/main16.o 116/ll.o

117/main17: 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 117/main17.o
	$(CC) $(CFLAGS) -o $@ 117/main17.o 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 

117/main18: 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 117/main18.o
	$(CC) $(CFLAGS) -o $@ 117/main18.o 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 

117/main19: 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 117/main19.o
	$(CC) $(CFLAGS) -o $@ 117/main19.o 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 

117/main20: 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 117/main20.o
	$(CC) $(CFLAGS) -o $@ 117/main20.o 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 

117/main21: 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 117/main21.o
	$(CC) $(CFLAGS) -o $@ 117/main21.o 117/ll.o 117/ll_string.o 117/ll_list.o 117/ll_int.o 117/ll_double.o 

clean:
	rm -f *.o ${ALL_TARGETS} 

