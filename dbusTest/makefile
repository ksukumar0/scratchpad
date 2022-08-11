CC=gcc
CFLAGS= -fstack-protector
OFLAGS = -O2
#STDFLAGS = -std=c++14

LIBS = $(shell pkg-config --cflags dbus-1)
#VERBOSE=-v

LD_FLAGS = -L/usr/lib/arm-linux-gnueabihf -ldbus-1

ifdef WFLAGS
	${WFLAGS}
	WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

DBUS_TEST = dbusTest.o

dbusTest: $(DBUS_TEST)
	$(CC) -o dbusTest $(VERBOSE) $(LD_FLAGS) $(DBUS_TEST)
	@echo "Linking $<"

%.o: %.c
	$(CC) -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< $(WFLAGS) $(LIBS) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
