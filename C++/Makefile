GCC = gcc -gstabs+
LIB = 
current_dir = $(notdir $(shell pwd))

all:
	${GCC} -c *.c
	${GCC} -o ${current_dir} *.o -l ${LIB}
