GCC = gcc -gstabs+
LIB = 
current_dir = $(notdir $(shell pwd))

all:
	${GCC} -c *.c
	${GCC} -S -masm=intel *.c
	${GCC} -o ${current_dir} *.o
