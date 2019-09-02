CC=gcc
CFLAGS=-I.
DEPS = getopt.h
OBJ = getopt.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

getopt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lpthread

