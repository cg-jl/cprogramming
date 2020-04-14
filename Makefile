C_COMMAND=gcc
C_FLAGS= -g -Wall

printf_scanf:
	$(C_COMMAND) $(C_FLAGS) -o printf_scanf printf_scanf.c
