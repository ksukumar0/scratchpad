CC=gcc
CFLAGS=-I. -fprofile-arcs -ftest-coverage
DEPS = getopt.h
OBJ = getopt.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

getopt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lpthread

