C_COMMAND=gcc
C_FLAGS= -g -Wall


all_exec: printf_scanf

printf_scanf:
	$(C_COMMAND) $(C_FLAGS) -o printf_scanf practices/own_stdlib_functions/printf_scanf.c

clean_exec:
	$(RM) printf_scanf
