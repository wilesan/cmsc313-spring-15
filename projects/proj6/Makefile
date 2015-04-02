################################################################
#
#
################################################################

CC=gcc
CFLAGS=-m32 -g
.PREFIXES= .c .o

ALL_TARGETS=main6 hexdump

C_SOURCE=main6.c buf_desc.c hexdump.c

C_OBJECTS=${C_SOURCE:.c=.o}

all: ${ALL_TARGETS}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

main6: main6.o buf_desc.o
	${CC} ${CFLAGS} -o $@ main6.o buf_desc.o

hexdump: hexdump.c
	${CC} ${CFLAGS} -o $@ $<
	
clean:
	rm -f *.o ${ALL_TARGETS}

