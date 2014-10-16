NASM = nasm -f elf64 -g
GCC = gcc -gstabs+
LD = ld
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.o ${current_dir}.asm
	${LD} -o ${current_dir}.out ${current_dir}.o
	${GCC} -o ${current_dir} ${current_dir}.o

