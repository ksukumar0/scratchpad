CC=gcc
CFLAGS= -I
OFLAGS = -O2
#STDFLAGS = -std=c++14
ifdef WFLAGS 
	echo $(WFLAGS)
	WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

UNION_OBJS = union_test.o nodeID.o
CONST_OBJS = const_test.o
TEST_OBJS = test.o
PTR_OBJS = ptr.o
STAT_OBJS = statTest.o

ptr: $(PTR_OBJS)
	$(CC) -g -o ptr $(PTR_OBJS)

test: $(TEST_OBJS)
	$(CC) -g -o test $(TEST_OBJS)

const_test: $(CONST_OBJS)
	$(CC) -o const_test $(CONST_OBJS)

union_test: $(UNION_OBJS)
	$(CC) -o union_test $(UNION_OBJS)

statTest: $(STAT_OBJS)
	$(CC) -o statTest $(STAT_OBJS)

%.o: %.c
	$(CC) -g -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< $(WFLAGS) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
