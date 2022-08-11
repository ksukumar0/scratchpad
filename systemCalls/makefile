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

STAT_OBJS = statTest.o

statTest: $(STAT_OBJS)
	$(CC) -o statTest -lutil $(STAT_OBJS)

%.o: %.c
	$(CC) -g -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< $(WFLAGS) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
