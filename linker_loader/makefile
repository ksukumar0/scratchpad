CC=gcc
CFLAGS= -I -Wimplicit-function-declaration
OFLAGS = -O2
#STDFLAGS = -std=c++14

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

#LKR_OBJS = $(OBJS) #lkr.o
LKR_OBJS = lkr.o ./libprint1.a

lkr: $(LKR_OBJS)
	$(CC) -o lkr $(LKR_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $< -o $@


clean:
	rm -rf *.o
