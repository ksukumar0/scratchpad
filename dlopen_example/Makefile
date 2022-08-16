CC = gcc
app = dlopen_sample
lib = libcat.so libdog.so

CFLAGS = -Wall -ansi -pedantic
LDLIBS = -ldl

all: $(app) $(lib)

lib%.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

clean:
	$(RM) $(app) $(lib)

run: all
	./$(app) cat
	./$(app) dog
	-./$(app) bear

$(app): 
	$(CC) $(CFLAGS) dlopen_sample.c -o $@ -Wl,-rpath=/lib/x86_64-linux-gnu/ $(LDLIBS)

$(lib): animal.h
