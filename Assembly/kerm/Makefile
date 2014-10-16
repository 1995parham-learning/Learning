NASM = nasm -f elf64 -g
LD = ld
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.o ${current_dir}.asm
	${LD} -o ${current_dir} ${current_dir}.o

