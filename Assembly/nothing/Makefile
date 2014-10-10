NASM = nasm -f elf64 -g
GCC = gcc -gstabs+
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.asm.o ${current_dir}.asm
	${GCC} -c -o ${current_dir}.c.o ${current_dir}.c
	${GCC} -o ${current_dir} ${current_dir}.c.o ${current_dir}.asm.o

