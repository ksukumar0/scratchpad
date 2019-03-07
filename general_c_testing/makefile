CC=gcc
CFLAGS= -I
OFLAGS = -O2
#STDFLAGS = -std=c++14

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

CONST_OBJS = const_test.o
TEST_OBJS = test.o
PTR_OBJS = ptr.o

ptr: $(PTR_OBJS)
	$(CC) -g -o ptr $(PTR_OBJS)

test: $(TEST_OBJS)
	$(CC) -g -o test $(TEST_OBJS)

const_test: $(CONST_OBJS)
	$(CC) -o const_test $(CONST_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< -o $@

clean:
	rm -rf *.o
