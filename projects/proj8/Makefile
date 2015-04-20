################################################################
#
#
################################################################

CC=gcc
AS=nasm
CFLAGS=-m32 -g -pthread
ASFLAGS=-f elf -g -F dwarf

.PREFIXES= .c .o

ALL_TARGETS=main8

C_SOURCE=main8.c rot13_dev.c

C_OBJECTS=${C_SOURCE:.c=.o}

all: ${ALL_TARGETS}

%.o: %.c
	${CC} -fno-stack-protector -c ${CFLAGS} $< -o $@

main8.o: main8.c rot13_dev.h

main8: main8.o rot13_dev.o
	${CC} ${CFLAGS} -o $@ main8.o rot13_dev.o

clean:
	rm -f *.o ${ALL_TARGETS}

