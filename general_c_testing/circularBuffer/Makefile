CC = gcc
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = 

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))
EXENAME=circularBuffer

.PHONY: all

all: ${EXENAME} lib${EXENAME}.so

%.o: %.c
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

${EXENAME}: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o circularBuffer $(OBJS)

lib${EXENAME}.so: circularBuffer.o
	$(CC) -shared $< -o $@

clean:
	rm -rf *.o circularBuffer
