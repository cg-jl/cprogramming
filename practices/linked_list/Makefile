NAME=main
CC=gcc
CFLAGS=-Wall -Wextra
OBJ = $(NAME).o List.o
DEPS = List.h
LDFLAGS=

%.o: %.c $(DEPS)
	gcc -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(NAME)
	rm -f $(OBJ)
