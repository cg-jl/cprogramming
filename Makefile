C_COMMAND=gcc
C_FLAGS= -g -Wall


all_exec: own_stdlib_exec

########## practices/own_stdlib_functions ###############

own_stdlib_exec: printf scanf

printf:
	$(C_COMMAND) $(C_FLAGS) -o printf practices/own_stdlib_functions/printf.c

scanf:
	$(C_COMMAND) $(C_FLAGS) -o scanf practices/own_stdlib_functions/scanf.c


######## Cleaning ############

clean_exec: clean_own_stdlib_exec


clean_own_stdlib_exec:
	$(RM) printf scanf
