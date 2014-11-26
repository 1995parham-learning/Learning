NASM = nasm -f elf64 -g
GCC = gcc -gstabs+
LD = ld
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.o -l ${current_dir}.lst ${current_dir}.asm
	${LD} -o ${current_dir} -Map ${current_dir}.map ${current_dir}.o

