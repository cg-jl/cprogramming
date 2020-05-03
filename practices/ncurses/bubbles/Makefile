# Makefile
#
CC=gcc -g
CFLAGS=-Wall -Wextra -I. -lncurses -lm
DEPS = demoLoop.h demoBubble.h demoVector.h
OBJ = demo.o demoLoop.o demoBubble.o demoVector.o

all: clean demo
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

demo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o



.PHONY: clean

clean:
	rm -f *.o *~ core
