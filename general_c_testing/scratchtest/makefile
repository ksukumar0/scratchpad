CC=gcc
CFLAGS= #-fno-stack-protector
OFLAGS = #-O2
#STDFLAGS = -std=c++14

ifdef WFLAGS
	${WFLAGS}
	WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

TEST_OBJS = test.o

test: $(TEST_OBJS)
	$(CC) -o test $(TEST_OBJS)
%.o: %.c

	$(CC) -c -g $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< $(WFLAGS) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
