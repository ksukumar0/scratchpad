CC=gcc
CFLAGS= -I -Wimplicit-function-declaration
OFLAGS = -O2

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

crc: $(OBJS)
	$(CC) -o crc $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< -o $@

clean:
	rm -rf *.o
