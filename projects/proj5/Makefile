################################################################
#
#
################################################################

CC=gcc
CFLAGS=-m32 -g
.PREFIXES= .c .o

ALL_TARGETS=main5

C_SOURCE=main5.c book_info_heap.c

C_OBJECTS=${C_SOURCE:.c=.o}

all: ${ALL_TARGETS}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

${ALL_TARGETS}: ${C_OBJECTS}
	${CC} ${CFLAGS} -o $@ ${C_OBJECTS}

clean:
	rm -f *.o ${ALL_TARGETS}

