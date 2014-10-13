NASM = nasm -f elf64 -g
GCC = gcc -gstabs+
current_dir = $(notdir $(shell pwd))

all:
	${NASM} *.asm
	${GCC} -c *.c
	${GCC} -o ${current_dir} *.o

